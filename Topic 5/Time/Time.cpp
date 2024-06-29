#include "Time.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Time::Time(unsigned hours, unsigned mins, unsigned seconds)
{
    setHours(hours);
    setMins(mins);
    setSeconds(seconds);
}

unsigned Time::getHours() const
{
    return secondsFromMidnight / Constants::SECONDS_IN_HOURS;
}

unsigned Time::getMins() const
{
    return (secondsFromMidnight / Constants::SECONDS_IN_MINUTE) % Constants::SECONDS_IN_MINUTE;
}

unsigned Time::getSeconds() const
{
    return secondsFromMidnight % Constants::SECONDS_IN_MINUTE;
}

bool Time::setHours(unsigned hours)
{
    return validateAndSet(0, (Constants::HOURS_IN_DAY - 1), hours, getHours(), Constants::SECONDS_IN_HOURS);
}

bool Time::setMins(unsigned mins)
{
    return validateAndSet(0, (Constants::SECONDS_IN_MINUTE - 1), mins, getMins(), Constants::SECONDS_IN_MINUTE);
}

bool Time::setSeconds(unsigned seconds)
{
    return validateAndSet(0, (Constants::SECONDS_IN_MINUTE - 1), seconds, getSeconds(), 1);
}

void Time::tick()
{
    ++secondsFromMidnight %= Constants::DAY_SECONDS;
}

void Time::serialize(std::ostream& os) const
{
    os << std::setw(2) << std::setfill('0') << getHours() << ":"
        << std::setw(2) << std::setfill('0') << getMins() << ":"
        << std::setw(2) << std::setfill('0') << getSeconds() 
        << std::endl;
}

bool Time::validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned multiplier)
{
    if (newValue >= lowerBound && newValue <= upperBound)
    {
        (secondsFromMidnight -= (oldValue * multiplier)) += (newValue * multiplier);
        return true;
    }
    else
    {
        return false;
    }
}


int compareTimes(const Time& lhs, const Time& rhs)
{
    //we don't have access to the secondsFromMidnight
    // and we don't know what 'static' and 'friend' is at this point of the course.

    if (lhs.getHours() == lhs.getHours())
    {
        if (lhs.getMins() == rhs.getMins())
        {
            return lhs.getSeconds() - rhs.getSeconds();
        }
        else
        {
            return lhs.getMins() - rhs.getMins();
        }
    }
    else
    {
        return lhs.getHours() - rhs.getHours();
    }
}
