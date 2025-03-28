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
    m_character = std::make_shared<Character>(RESOURCE_DIR"/Image/Box/blue_box.png");
    m_character->SetPosition({0.0f, 125.0f});
    m_character->SetZIndex(50);
    m_Root.AddChild(m_character);

    m_Chest = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/chest.png");
    m_Chest->SetZIndex(5);
    m_Chest->SetPosition({197.5f, -3.5f});
    m_Chest->SetVisible(false);
    m_Root.AddChild(m_Chest);

    std::vector<std::string> beeImages;
    beeImages.reserve(2);
    for (int i = 0; i < 2; ++i) {
        beeImages.emplace_back(RESOURCE_DIR"/Image/Character/bee_" + std::to_string(i + 1) + ".png");
    }

    m_Bee = std::make_shared<AnimatedCharacter>(beeImages);
    m_Bee->SetZIndex(5);
    m_Bee->SetVisible(false);
    m_Root.AddChild(m_Bee);


    for (int i = 0; i < 3; ++i) {
        m_Doors.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Character/door_close.png"));
        m_Doors[i]->SetZIndex(5);
        m_Doors[i]->SetPosition({205.5f - 80.f * i, -3.5f});
        m_Doors[i]->SetVisible(false);
        m_Root.AddChild(m_Doors[i]);
    }

    // TODO: The counting down ball for phase 6
    std::vector<std::string> ballImages;
    ballImages.reserve(4);
    for (int i = 3; i >= 0; --i) {
        if (i==0) {
            ballImages.emplace_back(RESOURCE_DIR"/Image/Character/ball-ok.png");
        }
        else {
            ballImages.emplace_back(RESOURCE_DIR"/Image/Character/ball-" + std::to_string(i) + ".png");
        }
    }
    m_Ball = std::make_shared<AnimatedCharacter>(ballImages);
    m_Ball->SetZIndex(5);
    m_Ball->SetCooldown(1000);
    m_Ball->SetPivot({112.5, 140.5});
    m_Ball->SetVisible(false);
    m_Root.AddChild(m_Ball);

    m_CurrentState = State::UPDATE;
    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildren());
    m_CurrentState = State::UPDATE;
}

/*void App::Update() {
    
    //TODO: do your things here and delete this line <3

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
