#include "Object.hpp"

Object::Object(const std::string& name)
{
    mName = name;
    std::cout << AnsiColors.bold << "There is a " << name << ". " << AnsiColors.normal;
}

Object::~Object()
{
    // Dummy destructor...
}

std::string Object::getName()
{
    return mName;
}
