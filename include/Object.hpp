#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"

class Object : public Util::GameObject {
public:
    explicit Object(const std::string& ImagePath);

    Object(const Object&) = delete;

    Object(Object&&) = delete;

    Object& operator=(const Object&) = delete;

    Object& operator=(Object&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Object>& other) const {
        if((abs(GetPosition().x - other->GetPosition().x)<=20 &&(abs(GetPosition().y - other->GetPosition().y)<=20))){
            other->SetVisible(false);
            return true;
        }
        else {
            return false;
        }
    }
    bool IfOpen(const std::shared_ptr<Object>& other) const {
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

class BoxCharacter : public Object {
public:
    explicit BoxCharacter(const std::string& path) : Object(path) {}
    CharacterType GetType() const { return CharacterType::Box; }
};

class WallCharacter : public Object {
public:
    explicit WallCharacter(const std::string& path) : Object(path) {}
    CharacterType GetType() const { return CharacterType::Wall; }
};

#endif //CHARACTER_HPP
