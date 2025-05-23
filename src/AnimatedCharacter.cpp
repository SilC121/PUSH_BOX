#include "AnimatedCharacter.hpp"


AnimatedCharacter::AnimatedCharacter(const std::vector<std::string>& AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}


