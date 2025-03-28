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
            break;

        case Phase::Playing:
            if (true) {
                m_Phase = Phase::Playing;
                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("Playing");
            }
            break;
    }
}
