#ifndef TIMETRAVELCOMPONENT_HPP
#define TIMETRAVELCOMPONENT_HPP

#include "Core.hpp"

class Timeline;

class TimeTravelComponent
{
    public:
        TimeTravelComponent(Timeline* timeline);
        ~TimeTravelComponent();

        void travel(const Year& destination);

    private:
        Timeline* mTimeline;
};

#endif // TIMETRAVELCOMPONENT_HPP
