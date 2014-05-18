#ifndef BOOK_HPP
#define BOOK_HPP

#include "Chapter.hpp"
#include "Chapter01.hpp"
//#include "Chapter02.hpp"
//#include "Chapter03.hpp"

class Book
{
    public:
        Book(const std::string& title, const std::string& author);
        ~Book();

        void startReading();

    private:
        Chapter* mChapters[14];
        std::string mAuthor;
        std::string mTitle;
};

#endif // BOOK_HPP
