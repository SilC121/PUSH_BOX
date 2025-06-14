#include "App.hpp"

#include <fstream>
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Logger.hpp"
#include "Util/BGM.hpp"

void App::Start() {
    LOG_TRACE("Start");
    BGM = std::make_shared<Util::BGM>(RESOURCE_DIR"/BGM/Boxxle-Soundtrack.mp3");
    BGM->SetVolume(60);
    BGM->Play();
    AnimateSet("down");
    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildrenP());
    m_CurrentState = State::UPDATE;
}
void App::AnimateSet(std::string path){
    glm::vec2 pos ={0,0};
    if (m_CurrentState == State::UPDATE) {
        pos = m_people->GetPosition();
        m_Root.RemoveChild(m_people);
    }
    std::vector<std::string> person_direction;
    if (path=="up") {
        person_direction.reserve(3);
        for (int i = 0; i < 3; ++i) {
            person_direction.emplace_back(RESOURCE_DIR"/Image/Character/person_up_" + std::to_string(i + 1) + ".png");
        }
        person_direction.emplace_back(RESOURCE_DIR"/Image/Character/person_up_2.png");
    }
    else if(path =="down") {
        person_direction.reserve(3);
        for (int i = 0; i < 3; ++i) {
            person_direction.emplace_back(RESOURCE_DIR"/Image/Character/person_down_" + std::to_string(i + 1) + ".png");
        }
        person_direction.emplace_back(RESOURCE_DIR"/Image/Character/person_down_2.png");
    }
    else if(path =="left") {
        person_direction.reserve(2);
        for (int i = 0; i < 2; ++i) {
            person_direction.emplace_back(RESOURCE_DIR"/Image/Character/person_left_" + std::to_string(i + 1) + ".png");
        }
    }
    else {
        person_direction.reserve(2);
        for (int i = 0; i < 2; ++i) {
            person_direction.emplace_back(RESOURCE_DIR"/Image/Character/person_right_" + std::to_string(i + 1) + ".png");
        }
    }
    m_people = std::make_shared<AnimatedCharacter>(person_direction);
    if (m_CurrentState == State::START) {
        m_people->SetVisible(false);
    }
    else {
        m_people->SetVisible(true);
    }
    m_people->SetZIndex(5);
    m_people->SetLooping(true);
    m_people->SetPlaying();
    m_people->SetPosition(pos);
    m_Root.AddChild(m_people);
}
void App::LoadLevel() {
    Clean(Wall_all);
    Wall_all.clear();
    Clean(Floor_all);
    Floor_all.clear();
    Clean(Box_all);
    Box_all.clear();
    Clean(Goal_all);
    Goal_all.clear();
    LoadLevelFromTxt();
}

void App::Clean(std::vector<std::shared_ptr<Object>> obj) {
    for (int i = 0; i < obj.size(); i++) {
        m_Root.RemoveChild(obj[i]);
    }
}

bool IsBlocked(const glm::vec2& pos, const std::vector<std::shared_ptr<Object>>& blocks){
    for (const auto& b : blocks){
        if (glm::distance(b->GetPosition(), pos) < 1e-2f){
            return true;
        }
    }
    return false;
}

std::shared_ptr<Object> GetBoxAt(const glm::vec2& pos, const std::vector<std::shared_ptr<Object>>& boxes) {
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
    if (IsBlocked(next, Wall_all)) return;
    auto box = GetBoxAt(next, Box_all);
    if (box) {
        glm::vec2 boxNext = next + dir;
        if (IsBlocked(boxNext, Wall_all) || IsBlocked(boxNext, Box_all)) return;
        box->SetPosition(boxNext);
    }
    m_people->SetPosition(next);
}

