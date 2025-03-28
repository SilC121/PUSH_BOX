#include "AppUtil.hpp"
#include "App.hpp"

#include "Util/Logger.hpp"

/**
 * @brief The function to validate the tasks.
 * @warning Do not modify this function.
 * @note See README.md for the task details.
 */
void App::ValidTask() {
    bool isBeeLooping;
    bool isBeePlaying;
    LOG_DEBUG("Validating the task {}", static_cast<int>(m_Phase));
    switch (m_Phase) {
        case Phase::CHANGE_CHARACTER_IMAGE:
            m_Phase = Phase::ABLE_TO_MOVE;
            m_character->SetPosition({-112.5f, -140.5f});
            m_PRM->NextPhase();
            break;

        case Phase::ABLE_TO_MOVE:
            if (isInsideTheSquare(*m_character)) {
                m_Phase = Phase::COLLIDE_DETECTION;
                m_character->SetPosition({-112.5f, -140.5f});
                m_Chest->SetVisible(true);

                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("The giraffe is not inside the square");
            }
            break;

        case Phase::COLLIDE_DETECTION:
            if (m_character->IfCollides(m_Chest)) {
                if (m_Chest->GetVisibility()) {
                    LOG_DEBUG("The giraffe collided with the chest but the chest is still visible");
                } else {
                    m_Phase = Phase::BEE_ANIMATION;
                    m_character->SetVisible(false);
                    m_Bee->SetVisible(false);
                    m_Bee->SetLooping(true);
                    m_Bee->SetPlaying();

                    m_PRM->NextPhase();
                }
            } else {
                LOG_DEBUG("The giraffe is not colliding with the chest");
            }
            break;

        case Phase::BEE_ANIMATION:
            isBeeLooping = m_Bee->IsLooping();
            isBeePlaying = m_Bee->IsPlaying();

            if (isBeeLooping && isBeePlaying) {
                m_Phase = Phase::OPEN_THE_DOORS;
                m_character->SetPosition({-112.5f, -140.5f});
                m_character->SetVisible(true);
                m_Bee->SetVisible(false);
                std::for_each(m_Doors.begin(), m_Doors.end(), [](const auto& door) { door->SetVisible(true); });

                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("The bee animation is {} but not {}", isBeeLooping ? "looping" : "playing",
                          isBeeLooping ? "playing" : "looping");
            }
            break;

        case Phase::OPEN_THE_DOORS:
            if (AreAllDoorsOpen(m_Doors)) {
                m_Phase = Phase::COUNTDOWN;
                std::for_each(m_Doors.begin(), m_Doors.end(), [](const auto& door) { door->SetVisible(false); });
                m_character->SetVisible(false);
                m_Ball->SetVisible(true);
                m_Ball->SetPlaying();
                m_PRM->NextPhase();
            } else {
                for (int i =0;i<3;i++){
                    if(m_character->IfOpen(m_Doors[i])) {
                        m_Doors[i]->SetImage(RESOURCE_DIR"/Image/Character/door_open.png");
                    };
                }
                LOG_DEBUG("At least one door is not open");
            }
            break;

        case Phase::COUNTDOWN:
            if (m_Ball->IfAnimationEnds()) {
                LOG_DEBUG("Congratulations! You have completed Giraffe Adventure!");
                m_CurrentState = State::END;
            } else{
                LOG_DEBUG("The ball animation is not ended");
            }
            break;
    }
}
