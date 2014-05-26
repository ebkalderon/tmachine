#include "Timeline.hpp"

Timeline::Timeline(const Year& current)
{
    std::cout << "The year is " << current << ".\n";
    mYear = current;
}

Timeline::~Timeline()
{
    clear();
}

void Timeline::clear()
{
    mChronBuffer.clear();
    mChronology.clear();
}

void Timeline::insertEntry(const Year& year, const Event& event)
{
    mChronBuffer.push_back(std::make_pair(year, event));
}

void Timeline::removeEntry(int index)
{
    mChronology.erase(mChronology.begin() + index);
}

void Timeline::swapEntries(int index1, int index2)
{
    std::pair<Year, Event> first = mChronology[index1];
    mChronology[index1] = mChronology[index2];
    mChronology[index2] = first;
}

void Timeline::update(std::vector<Character*> characters, const std::string& location)
{
    std::cout << "You're in " << location << ".\n";
    Event tmpEvent;

    for (std::pair<Year, Event> ev : mChronBuffer)
    {
        tmpEvent = ev.second;
        tmpEvent(characters, location);
        mChronology.push_back(ev);
    }

    sortAllEvents();
    mChronBuffer.clear();
}


std::vector<std::pair<Year, Event>>* Timeline::getChronology()
{
    return &mChronology;
}

Year* Timeline::getCurrentYear()
{
    return &mYear;
}

Event* Timeline::getEvent(int index)
{
    return &mChronology[index].second;
}

void Timeline::sortAllEvents()
{
    // Provided our Timeline has entries in it, sort them in ascending order
    // using a selection sort.
    if (mChronology.size() > 0)
    {
        unsigned int i, j;

        for (i = 1; i < mChronology.size(); i++)
        {
            j = i;
            while (j > 0 && mChronology[j - 1].first > mChronology[j].first)
            {
                swapEntries(j, j - 1);
                j--;
            }
        }
    }
}
