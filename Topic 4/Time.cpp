#include <iostream>
#include <fstream>
#include <iomanip>

namespace Constants
{
	constexpr unsigned SECONDS_IN_HOURS = 3600;
	constexpr unsigned SECONDS_IN_MINUTE = 60;
	constexpr unsigned SECONDS_IN_DAY = 24 * 3600;
	constexpr unsigned HOURS_IN_DAY = 24;
}

class Time
{
	unsigned secondsFromMidnight;

	bool validateAndSet(unsigned lowerBound, unsigned upperBound, unsigned newValue,
						unsigned oldVlaue, unsigned multiplier)
	{

		if (newValue >= lowerBound && newValue <= upperBound)
		{
			(secondsFromMidnight -= (oldVlaue * multiplier)) += (newValue * multiplier);
			return true;
		}
		else
		{
			return false;
		}
	}

public:

	Time() : secondsFromMidnight(0)
	{}

	Time(unsigned hours, unsigned mins, unsigned seconds)
	{
		setHours(hours);
		setMins(mins);
		setSeconds(seconds);
	}

	unsigned getHours() const
	{
		return secondsFromMidnight / Constants::SECONDS_IN_HOURS;
	}

	unsigned getMinutes() const
	{
		return (secondsFromMidnight / Constants::SECONDS_IN_MINUTE) % Constants::SECONDS_IN_MINUTE;
	}

	unsigned getSeconds() const
	{
		return secondsFromMidnight % Constants::SECONDS_IN_MINUTE;
	}

	bool setHours(unsigned hours)
	{
		return validateAndSet(0, (Constants::HOURS_IN_DAY - 1), hours, getHours(), Constants::SECONDS_IN_HOURS);
	}

	bool setMins(unsigned mins)
	{
		return validateAndSet(0, (Constants::SECONDS_IN_MINUTE - 1), mins, getMinutes(), Constants::SECONDS_IN_MINUTE);
	}

	bool setSeconds(unsigned seconds)
	{
		return validateAndSet(0, (Constants::SECONDS_IN_MINUTE - 1), seconds, getSeconds(), 1);
	}

	void tick()
	{
		++secondsFromMidnight %= Constants::SECONDS_IN_DAY;
	}

	void serialize(std::ostream& os) const
	{
		os << std::setw(2) << std::setfill('0') << getHours() << ":"
			<< std::setw(2) << std::setfill('0') << getMinutes() << ":"
			<< std::setw(2) << std::setfill('0') << getSeconds() 
			<< std::endl;
	}
};

int main()
{
	Time t(1, 22, 33);

	t.setMins(30);
	t.setSeconds(0);

	t.serialize(std::cout);
	t.tick();
	t.serialize(std::cout);

	return 0;
}
