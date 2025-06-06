#include "PhaseResourceManger.hpp"
#include "Util/Logger.hpp"

PhaseResourceManger::PhaseResourceManger() {
    m_TaskText = std::make_shared<TaskText>();
    m_Background = std::make_shared<BackgroundImage>();
}

void PhaseResourceManger::NextPhase() {
    LOG_DEBUG("Passed! Next phase: {}", m_Phase);
    m_Background->NextPhase(m_Phase);
    if (m_Phase == 1) {
        m_TaskText->NextPhase(m_Phase++);
        m_TaskText->SetPivot({-400,-310});
    }else {
        m_TaskText->SetVisible(false);
    }
}
