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
    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

private:
    State m_CurrentState = State::START;
    enum class Phase {
        Start,
        Playing,
        End,
        Introduction,
    };
    Phase m_Phase = Phase::Start;
    Util::Renderer m_Root;
    std::shared_ptr<AnimatedCharacter> m_people;

    std::shared_ptr<PhaseResourceManger> m_PRM;
    bool m_EnterDown = false;
};

#endif
