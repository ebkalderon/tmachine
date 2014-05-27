#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Core.hpp"

class GlowComponent;
class TimeTravelComponent;

class Object
{
    public:
        Object(const std::string& name);
        ~Object();

        GlowComponent* glow;
        TimeTravelComponent* engine;

        std::string getName();

    private:
        std::string mName;
};

#endif // OBJECT_HPP
