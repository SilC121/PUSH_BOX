#include "App.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
void App::Update(){
    if (Util::Input::IsKeyUp(Util::Keycode::W) ){
        TryMovePlayer({0,30});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::A) ) {
        TryMovePlayer({-30,0});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::S) ) {
        TryMovePlayer({0,-30});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::D) ) {
        TryMovePlayer({30,0});
    }
    if (Util::Input::IsKeyUp(Util::Keycode::N) ) {
        Lv++;
        LoadLevel();
        LOG_DEBUG("Level {} !",Lv);
    }
    if (Util::Input::IsKeyUp(Util::Keycode::B) ) {
        Lv--;
        LoadLevel();
        LOG_DEBUG("Level {} !",Lv);
    }
    if (Util::Input::IsKeyUp(Util::Keycode::R) ) {
        LoadLevel();
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
