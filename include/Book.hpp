#ifndef BOOK_HPP
#define BOOK_HPP

#include <vector>
#include "Chapter.hpp"
#include "Chapter01.hpp"
//#include "Chapter02.hpp"
//#include "Chapter03.hpp"

class Object;
class Timeline;

class Book
{
    public:
        Book(const std::string& title, const std::string& author);
        ~Book();

        void addCharacter(Character newPerson);
        void addObject(Object newObject);
        void startReading();

        std::vector<Character>* getCharacters();
        std::vector<Object>* getObjects();

        void setTimeline(Timeline* emptyTimeline);

    private:
        //Chapter* mChapters[14];
        Chapter* mChapters[1];
        Character* mNarrator;
        std::vector<Character> mCharacters;
        std::vector<Object> mObjects;
        std::string mAuthor;
        std::string mTitle;
        Timeline* mTimeline;
};

#endif // BOOK_HPP
