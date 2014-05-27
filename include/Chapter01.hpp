#ifndef CHAPTER01_HPP
#define CHAPTER01_HPP

#include "Chapter.hpp"

class Chapter01 : public Chapter
{
    public:
        ~Chapter01();
        virtual void read(std::vector<Character>* persistentCharacters, std::vector<Object>* persistentObjects, Timeline* timeline);
};

#endif // CHAPTER01_HPP
