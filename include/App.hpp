#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export
#include "Util/Renderer.hpp"
#include "Util/BGM.hpp"
#include "Object.hpp"
#include "PhaseResourceManger.hpp"
#include "AnimatedCharacter.hpp"

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }
    void LoadLevelFromTxt();
    void TryMovePlayer(const glm::vec2& dir);
    bool CheckWinCondition();
    void LoadLevel();
    void Clean(std::vector<std::shared_ptr<Object>> obj);
    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)
    void SetLevelText();
private:
    void ValidTask();
    State m_CurrentState = State::START;
    enum class Phase {
        Start,
        Playing,
        End,
        Introduction,
    };
    Phase m_Phase = Phase::Start;
    Util::Renderer m_Root;
    Util::Renderer m_level;
    std::shared_ptr<AnimatedCharacter> m_people;
    std::vector<std::shared_ptr<Object>> Floor_all;
    std::vector<std::shared_ptr<Object>>  Wall_all;
    std::vector<std::shared_ptr<Object>>  Box_all;
    std::vector<std::shared_ptr<Object>>  Goal_all;
    std::shared_ptr<TaskText> m_TaskText;
    std::shared_ptr<PhaseResourceManger> m_PRM;
    std::shared_ptr<Util::BGM> BGM;
    int Lv =1;
    bool m_EnterDown = false;
};

#endif
