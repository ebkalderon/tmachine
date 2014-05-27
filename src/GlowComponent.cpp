#include "GlowComponent.hpp"

GlowComponent::GlowComponent(const bool& lit, const int& glowCount)
{
    mGlowCount = glowCount;
    isLit(lit);
}

GlowComponent::~GlowComponent()
{
    // Dummy destructor...
}

bool GlowComponent::isLit()
{
    return mLit;
}

void GlowComponent::isLit(const bool& lit)
{
    mLit = lit;
    std::cout << AnsiColors.bold
              << ((mGlowCount == 1)  ? "It is " : "They are ")
              << (mLit ? "glowing brightly." : "dim.") << AnsiColors.normal << "\n";
}
