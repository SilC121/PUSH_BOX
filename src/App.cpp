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
    m_people->SetVisible(false);
    m_people->SetLooping(true);
    m_people->SetPlaying();
    m_Root.AddChild(m_people);
    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildrenP());
    m_CurrentState = State::UPDATE;
}

void App::LoadLevel(const std::string& path) {
    Clean(Wall_all);
    Wall_all.clear();
    Clean(Floor_all);
    Floor_all.clear();
    Clean(Box_all);
    Box_all.clear();
    Clean(Goal_all);
    Goal_all.clear();
    LoadLevelFromTxt(path);
}
void App::Clean(std::vector<std::shared_ptr<Character>> obj) {
    for (int i = 0; i < obj.size(); i++) {
        m_Root.RemoveChild(obj[i]);
    }
}


bool IsBlocked(const glm::vec2& pos, const std::vector<std::shared_ptr<Character>>& blocks) {
    for (const auto& b : blocks) {
        if (glm::distance(b->GetPosition(), pos) < 1e-2f) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Character> GetBoxAt(const glm::vec2& pos, const std::vector<std::shared_ptr<Character>>& boxes) {
    for (const auto& box : boxes) {
        if (glm::distance(box->GetPosition(), pos) < 1e-2f) {
            return box;
        }
    }
    return nullptr;
}

void App::TryMovePlayer(const glm::vec2& dir) {
    glm::vec2 curr = m_people->GetPosition();
    glm::vec2 next = curr + dir;

    // 撞牆
    if (IsBlocked(next, Wall_all)) return;

    // 檢查箱子
    auto box = GetBoxAt(next, Box_all);
    if (box) {
        glm::vec2 boxNext = next + dir;
        // 箱子撞牆或撞其他箱子
        if (IsBlocked(boxNext, Wall_all) || IsBlocked(boxNext, Box_all)) return;

        // 箱子可以移動
        box->SetPosition(boxNext);
    }
    // 玩家移動
    m_people->SetPosition(next);
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
