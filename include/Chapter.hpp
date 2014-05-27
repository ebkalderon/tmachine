#ifndef CHAPTER_HPP
#define CHAPTER_HPP

#include <vector>
#include "Character.hpp"
#include "GlowComponent.hpp"
#include "Object.hpp"
#include "Timeline.hpp"
#include "TimeTravelComponent.hpp"

class Character;
class Object;
class Timeline;

class Chapter
{
    public:
        virtual ~Chapter() {};
        virtual void read(std::vector<Character>* persistentCharacters, std::vector<Object>* persistentObjects, Timeline* timeline) = 0;

        void setNarrator(Character person)
        {
            std::cout << AnsiColors.italic << person.getName() << " is now narrating.\n" << AnsiColors.normal;
            mNarrator = &person;
        }

    protected:
        Character* mNarrator;
};

#endif // CHAPTER_HPP
