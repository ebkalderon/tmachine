#ifndef CHAPTER_HPP
#define CHAPTER_HPP

#include <vector>
#include "Core.hpp"

class Character;
class Timeline;

class Chapter
{
    public:
        virtual ~Chapter() {};
        virtual void read(std::vector<Character*> persistentCharacters, Timeline* timeline) = 0;
};

#endif // CHAPTER_HPP
