#include "Book.hpp"

Book::Book(const std::string& title, const std::string& author)
{
    mAuthor = author;
    mTitle = title;

    // TODO: Create a set of 14 chapters in an array and use
    // a for-each to execute each read() method.
}

Book::~Book()
{
    // Dummy constructor...
}

void Book::startReading()
{
    for (Chapter* ch : mChapters)
    {
        ch->read();
    }
}
