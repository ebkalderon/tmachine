#include "Book.hpp"

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
    std::cout << AnsiColors.normal << AnsiColors.lightYellow << "\nThe end.\n" << AnsiColors.normal;
}

void Book::addCharacters(Character* newchar)
{
    // Let's make newchar a persistent character (a character which exists across multiple chapters).
    mCharacters.push_back(newchar); 
}

void Book::startReading()
{   
    for (Chapter* ch : mChapters)
    {
        ch->read(mCharacters, mTimeline);
    }
}


std::vector<Character*>* Book::getCharacters()
{
    return &mCharacters;
}

void Book::setNarrator(Character* person)
{
    std::cout << person->getName() << " is now narrating.\n";
    mNarrator = person;
}

void Book::setTimeline(Timeline* emptyTimeline)
{
    mTimeline = emptyTimeline;
}
