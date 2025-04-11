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
                if (CheckWinCondition()) {
                    LoadLevel(RESOURCE_DIR"/Level/Lv2.txt");
                }
                //m_PRM->NextPhase();
            } else {
                LOG_DEBUG("Playing");
            }
            break;
    }
}

bool App::CheckWinCondition() {
    for (const auto& goal : Goal_all) {
        bool hasBox = false;
        for (const auto& box : Box_all) {
            if (glm::distance(box->GetPosition(), goal->GetPosition()) < 1e-2f) {
                hasBox = true;
                break;
            }
        }
        if (!hasBox) return false;  // 有一個目標點沒箱子
    }
    return true;
}