#ifndef CHAPTER_HPP
#define CHAPTER_HPP

#include "Core.hpp"

class Chapter
{
    public:
        virtual ~Chapter() {};
        virtual void read() = 0;
};

#endif // CHAPTER_HPP
