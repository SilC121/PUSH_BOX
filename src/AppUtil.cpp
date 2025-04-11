#include "AppUtil.hpp"
#include "App.hpp"

#include "Util/Logger.hpp"

/**
 * @brief The function to validate the tasks.
 * @warning Do not modify this function.
 * @note See README.md for the task details.
 */
void App::ValidTask() {
    LOG_DEBUG("Validating the task {}", static_cast<int>(m_Phase));
    switch (m_Phase) {
        case Phase::Start:
            m_Phase = Phase::Playing;
            m_PRM->NextPhase();
            m_people->SetVisible(true);
            LoadLevelFromTxt(RESOURCE_DIR"/Level/Lv1.txt");
            break;

        case Phase::Playing:
            if (true) {
                m_Phase = Phase::Playing;
                LoadLevel(RESOURCE_DIR"/Level/Lv2.txt");
                //m_PRM->NextPhase();
            } else {
                LOG_DEBUG("Playing");
            }
            break;
    }
}

/*bool App::CheckWinCondition() {
    for (auto& obj : m_Root.GetChildren()) {
        auto goal = std::dynamic_pointer_cast<Character>(obj);
        if (!goal || goal->GetType() != CharacterType::Goal) continue;

        bool hasBox = false;
        for (auto& maybeBox : m_Root.GetChildren()) {
            auto box = std::dynamic_pointer_cast<Character>(maybeBox);
            if (!box || box->GetType() != CharacterType::Box) continue;

            if (glm::distance(box->GetPosition(), goal->GetPosition()) < 10.0f) {
                hasBox = true;
                break;
            }
        }
        if (!hasBox) return false;
    }
    return true;
}*/