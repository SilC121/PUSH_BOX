#include "App.hpp"

#include <fstream>
#include "Util/GameObject.hpp"
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
    LoadLevelFromTxt(RESOURCE_DIR"/Level/Lv1.txt");
    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildrenP());
    m_CurrentState = State::UPDATE;
}

/*void App::LoadLevel(const std::string& path) {
    m_Root.RemoveChild();
    m_people->SetPosition({0, 0});
    LoadLevelFromTxt(path);
}*/
void App::LoadLevelFromTxt(const std::string& path) {
    std::ifstream file(path);
    std::string line;
    int row = 0;

    while (std::getline(file, line)) {
        for (int col = 0; col < line.size(); ++col) {
            char ch = line[col];
            glm::vec2 pos = {col * 30.0f, row * 30.0f};
            auto floor = std::make_shared<Character>(RESOURCE_DIR"/Image/Wall/concrete_floor.png");
                    floor->SetPosition(pos);
                    m_Root.AddChild(floor);
                    floor->SetZIndex(0);
            switch (ch) {
                case '#': {
                    auto wall = std::make_shared<Character>(RESOURCE_DIR"/Image/Wall/black_wall_circle.png");
                    wall->SetPosition(pos);
                    wall->SetZIndex(5);
                    m_Root.AddChild(wall);
                    break;
                }
                case '$': {
                    auto box = std::make_shared<Character>(RESOURCE_DIR"/Image/Box/blue_box.png");
                    box->SetPosition(pos);
                    m_Root.AddChild(box);
                    box->SetZIndex(5);
                    break;
                }
                case '.': {
                    auto goal = std::make_shared<Character>(RESOURCE_DIR"/Image/Box/blue_goal.png");
                    goal->SetPosition(pos);
                    m_Root.AddChild(goal);
                    goal->SetZIndex(5);
                    break;
                }
                case '@': {
                    m_people->SetPosition(pos);
                    break;
                }

            }
        }
        row++;
    }
}
/*
void App::TryMovePlayer(const glm::vec2& dir) {
    glm::vec2 current = m_people->GetPosition();
    glm::vec2 next = current + dir;

    // 檢查碰撞：牆壁/箱子
    for (auto& obj : m_Root.GetChildren()) {
        auto c = std::dynamic_pointer_cast<Character>(obj);
        if (!c || c == m_people) continue;

        if (glm::distance(c->GetPosition(), next) < 20.0f) {
            if (c->GetType() == CharacterType::Wall) return;

            if (c->GetType() == CharacterType::Box) {
                glm::vec2 boxNext = next + dir;

                // 確認箱子下一格是否能前進
                for (auto& other : m_Root.GetChildren()) {
                    auto block = std::dynamic_pointer_cast<Character>(other);
                    if (!block || block == m_people || block == c) continue;

                    if (glm::distance(block->GetPosition(), boxNext) < 20.0f &&
                        block->GetType() != CharacterType::Goal) {
                        return;
                        }
                }
                c->SetPosition(boxNext); // 推箱子
            }
        }
    }
    m_people->SetPosition(next);
}
*/


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
