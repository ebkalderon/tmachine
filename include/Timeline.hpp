#ifndef TIMELINE_HPP
#define TIMELINE_HPP

#include <utility>
#include <vector>
#include "Core.hpp"

class Character;
class Object;
typedef void (*Event)(std::vector<Character>*, std::vector<Object>*, const std::string&); // http://stackoverflow.com/questions/4295432/typedef-function-pointer
     
class Timeline
{
    public:
        Timeline(const Year& current);
        ~Timeline();
                
        void clear();
        void insertEntry(const Year& year, const Event& event);
        void removeEntry(int index);
        void swapEntries(int index1, int index2);
        void update(std::vector<Character>* characters, std::vector<Object>* objects, const std::string& location);
                
        std::vector<std::pair<Year, Event>>* getChronology();
        Year getCurrentYear();
        Event* getEvent(int index);

        Year mYear;

    private:
        void sortAllEvents();
        std::vector<std::pair<Year, Event>> mChronBuffer;
        std::vector<std::pair<Year, Event>> mChronology;
};

#endif // TIMELINE_HPP
