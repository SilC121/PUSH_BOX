#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export


#include "Util/Renderer.hpp"
#include "Character.hpp"
#include "Util/Text.hpp"
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
    void LoadLevelFromTxt(const std::string& path);
    void TryMovePlayer(const glm::vec2& dir);
    bool CheckWinCondition();
    void LoadLevel(const std::string& path);
    void Clean(std::vector<std::shared_ptr<Character>> obj);
    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)

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
    std::vector<std::shared_ptr<Character>> Floor_all;
    std::vector<std::shared_ptr<Character>>  Wall_all;
    std::vector<std::shared_ptr<Character>>  Box_all;
    std::vector<std::shared_ptr<Character>>  Goal_all;
    std::shared_ptr<PhaseResourceManger> m_PRM;
    bool m_EnterDown = false;
};

#endif
