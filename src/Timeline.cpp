#include "Timeline.hpp"

Timeline::Timeline(const Year& current)
{
    std::cout << "Year is " << current << ".\n";
    mYear = current;
}

Timeline::~Timeline()
{
    clearChronology();
}

void Timeline::clearChronology()
{
    mChronology.clear();
}

void Timeline::insertEvent(Event* newEvent)
{
    mChronology.push_back(newEvent);
}

void Timeline::removeEvent(int index)
{
    mChronology.erase(mChronology.begin() + index);
}

void Timeline::reorderEvents(int index1, int index2)
{
    Event* first = mChronology[index1];
    mChronology[index1] = mChronology[index2];
    mChronology[index2] = first;
}

std::vector<Event*>* Timeline::getChronology()
{
    return &mChronology;
}

Year* Timeline::getCurrentYear()
{
    return &mYear;
}

Event* Timeline::getEvent(int index)
{
    return mChronology[index];
}
