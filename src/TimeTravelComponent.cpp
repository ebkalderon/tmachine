#include "TimeTravelComponent.hpp"
#include "Timeline.hpp"

TimeTravelComponent::TimeTravelComponent(Timeline* timeline)
{
    mTimeline = timeline;
}

TimeTravelComponent::~TimeTravelComponent()
{
    // Dummy destructor...
}

void TimeTravelComponent::travel(const Year& destination)
{
    mTimeline->mYear = destination;
    std::cout << AnsiColors.cyan << "Traveled to year " << destination << " AD.\n" << AnsiColors.normal;
}
