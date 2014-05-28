#ifndef TIMETRAVELCOMPONENT_HPP
#define TIMETRAVELCOMPONENT_HPP

#include "Core.hpp"

class Character;
class Timeline;

class TimeTravelComponent
{
    public:
        TimeTravelComponent(Timeline* timeline);
        ~TimeTravelComponent();

        void travel(const Year& destination);
        Character* pilot;

    private:
        Timeline* mTimeline;
};

#endif // TIMETRAVELCOMPONENT_HPP
