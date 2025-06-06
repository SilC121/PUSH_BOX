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
private:

    void ResetPosition() { m_Transform.translation = {0, 0}; }
    std::string m_ImagePath;
};

#endif //CHARACTER_HPP
