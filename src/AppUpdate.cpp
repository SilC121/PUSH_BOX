#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update(){
    if (Util::Input::IsKeyUp(Util::Keycode::W) ){
        TryMovePlayer({0,30});
        //m_people->SetPosition({m_people->GetPosition().x,m_people->GetPosition().y+30});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::A) ) {
        TryMovePlayer({-30,0});
        //m_people->SetPosition({m_people->GetPosition().x-30,m_people->GetPosition().y});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::S) ) {
        TryMovePlayer({0,-30});
        //m_people->SetPosition({m_people->GetPosition().x,m_people->GetPosition().y-30});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::D) ) {
        TryMovePlayer({30,0});
        //m_people->SetPosition({m_people->GetPosition().x+30,m_people->GetPosition().y});
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
