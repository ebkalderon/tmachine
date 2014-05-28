#include "Book.hpp"
#include "Character.hpp"
#include "Object.hpp"

Book::Book(const std::string& title, const std::string& author)
{
    mAuthor = author;
    mTitle = title;

    mChapters[0] = new Chapter01();

    std::cout << AnsiColors.normal << AnsiColors.lightYellow << "Welcome to " << AnsiColors.italic << mTitle << AnsiColors.unitalic << "!\n" << AnsiColors.normal;
}

Book::~Book()
{
    // The book is finally over!
    std::cout << AnsiColors.lightMagenta << "<No more chapters>\n" << AnsiColors.normal;
    std::cout << AnsiColors.lightYellow << "\nThe end.\n" << AnsiColors.normal;
}

void Book::addCharacter(Character newPerson)
{
    // Let's make newchar a persistent character (a character which exists across multiple chapters).
    mCharacters.push_back(newPerson);
}

void Book::addObject(Object newObject)
{
    mObjects.push_back(newObject);
}

void Book::startReading()
{   
    for (Chapter* ch : mChapters)
    {
        ch->read(&mCharacters, &mObjects, mTimeline);
    }
}

std::vector<Character>* Book::getCharacters()
{
    return &mCharacters;
}

std::vector<Object>* Book::getObjects()
{
    return &mObjects;
}

void Book::setTimeline(Timeline* emptyTimeline)
{
    mTimeline = emptyTimeline;
}
