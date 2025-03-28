#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");
    std::vector<std::string> person_Images_up;
    person_Images_up.reserve(3);
    for (int i = 0; i < 3; ++i) {
        person_Images_up.emplace_back(RESOURCE_DIR"/Image/Character/pngperson_up_" + std::to_string(i + 1) + ".png");
    }
    person_Images_up.emplace_back(RESOURCE_DIR"/Image/Character/person_up_2.png");
    std::vector<std::string> person_Images_down;
    person_Images_down.reserve(3);
    for (int i = 0; i < 3; ++i) {
        person_Images_down.emplace_back(RESOURCE_DIR"/Image/Character/person_down_" + std::to_string(i + 1) + ".png");
    }
    person_Images_down.emplace_back(RESOURCE_DIR"/Image/Character/person_down_2.png");
    std::vector<std::string> person_Images_left;
    person_Images_left.reserve(2);
    for (int i = 0; i < 2; ++i) {
        person_Images_left.emplace_back(RESOURCE_DIR"/Image/Character/person_left_" + std::to_string(i + 1) + ".png");
    }
    std::vector<std::string> person_Images_right;
    person_Images_right.reserve(2);
    for (int i = 0; i < 2; ++i) {
        person_Images_right.emplace_back(RESOURCE_DIR"/Image/Character/person_right_" + std::to_string(i + 1) + ".png");
    }
    m_people = std::make_shared<AnimatedCharacter>(person_Images_down);
    m_people->SetZIndex(5);
    m_people->SetVisible(true);
    m_people->SetLooping(true);
    m_people->SetPlaying();
    m_Root.AddChild(m_people);

    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildren());
    m_CurrentState = State::UPDATE;
}

/*void App::Update() {
    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.

     if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
         Util::Input::IfExit()) {
         m_CurrentState = State::END;
     }
  }
*/

// void App::End() { // NOLINT(this method will mutate members in the future)
//    LOG_TRACE("End");}
