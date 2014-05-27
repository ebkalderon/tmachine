#ifndef GLOWCOMPONENT_HPP
#define GLOWCOMPONENT_HPP

#include "Core.hpp"

class GlowComponent
{
    public:
        GlowComponent(const bool& lit, const int& glowCount);
        ~GlowComponent();

        bool isLit();
        void isLit(const bool& lit);

    private:
        int mGlowCount;
        bool mLit;
};

#endif // GLOWCOMPONENT_HPP
