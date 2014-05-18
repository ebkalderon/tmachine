#ifndef TIMELINE_HPP
#define TIMELINE_HPP

#include <vector>
#include "Core.hpp"

class Character;
// http://stackoverflow.com/questions/4295432/typedef-function-pointer
typedef void (*Event)(Year, Character);
       
class Timeline
{
    public:
        Timeline(const Year& current);
        ~Timeline();
                
        void clearChronology();
        void insertEvent(Event* newEvent);
        void removeEvent(int index);
        void reorderEvents(int index1, int index2);
                
        std::vector<Event*>* getChronology();
        Year* getCurrentYear();
        Event* getEvent(int index);
            
    private:
        std::vector<Event*> mChronology;
        Year mYear;
};

#endif // TIMELINE_HPP
