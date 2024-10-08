#include "WeatherData.h"

int main()
{
	CWeatherData wd;

	CStatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay);

	CDisplay display;
	wd.RegisterObserver(display);

	wd.SetMeasurements(3, 0.7, 760);
	wd.SetMeasurements(4, 0.8, 761);

	wd.RemoveObserver(statsDisplay);

	wd.SetMeasurements(10, 0.8, 761);
	wd.SetMeasurements(-10, 0.8, 761);
	return 0;
}