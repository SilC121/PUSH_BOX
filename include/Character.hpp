#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        if((abs(GetPosition().x - other->GetPosition().x)<=20 &&(abs(GetPosition().y - other->GetPosition().y)<=20))){
            other->SetVisible(false);
            return true;
        }
        else {
            return false;
        }
    }
    bool IfOpen(const std::shared_ptr<Character>& other) const {
        if((abs(GetPosition().x - other->GetPosition().x)<=20 &&(abs(GetPosition().y - other->GetPosition().y)<=20))){
            return true;
        }
        else {
            return false;
        }
    }

private:

    void ResetPosition() { m_Transform.translation = {0, 0}; }
    std::string m_ImagePath;
};
    enum class CharacterType {
    Player,
    Wall,
    Box,
    Goal
};

class BoxCharacter : public Character {
public:
    explicit BoxCharacter(const std::string& path) : Character(path) {}
    CharacterType GetType() const { return CharacterType::Box; }
};

class WallCharacter : public Character {
public:
    explicit WallCharacter(const std::string& path) : Character(path) {}
    CharacterType GetType() const { return CharacterType::Wall; }
};

#endif //CHARACTER_HPP
