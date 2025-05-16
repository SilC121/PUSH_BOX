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
        if (Lv<37) {
            Lv++;
            LoadLevel();
            SetLevelText();
        }
        LOG_DEBUG("Level {} !",Lv);
    }
    if (Util::Input::IsKeyUp(Util::Keycode::B) ) {
        if (Lv>1 && Lv<37) {
            Lv--;
            LoadLevel();
            SetLevelText();
        }
        LOG_DEBUG("Level {} !",Lv);
    }
    if (Util::Input::IsKeyUp(Util::Keycode::R) && Lv < 37) {
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
    if (m_Phase==Phase::Playing) {
        ValidTask();
    }
    m_Root.Update();
}
