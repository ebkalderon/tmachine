#ifndef CHAPTER01_HPP
#define CHAPTER01_HPP

#include "Book.hpp"
#include "Character.hpp"
#include "Chapter.hpp"

class Chapter01 : public Chapter
{
    public:
        ~Chapter01();

        virtual void read(std::vector<Character*> persistentCharacters, Timeline* timeline);
};

#endif // CHAPTER01_HPP
