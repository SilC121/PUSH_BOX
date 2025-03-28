#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update(){
    if (Util::Input::IsKeyPressed(Util::Keycode::W)){
        m_people->SetPosition({m_people->GetPosition().x,m_people->GetPosition().y+5});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A) ) {
        m_people->SetPosition({m_people->GetPosition().x-5,m_people->GetPosition().y});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S) ) {
        m_people->SetPosition({m_people->GetPosition().x,m_people->GetPosition().y-5});
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D) ) {
        m_people->SetPosition({m_people->GetPosition().x+5,m_people->GetPosition().y});
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
