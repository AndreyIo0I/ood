#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include "Observer.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CDisplay: public IObserver<SWeatherInfo>
{
private:
	/*
	    Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую.
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(IObservable<SWeatherInfo>* observable, SWeatherInfo const& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	struct StatsData
	{
		std::string name;
		double min = std::numeric_limits<double>::infinity();
		double max = -std::numeric_limits<double>::infinity();
		double acc = 0;
		unsigned countAcc = 0;
	};

	static void UpdateData(StatsData & data, double newData)
	{
		if (data.min > newData)
		{
			data.min = newData;
		}
		if (data.max < newData)
		{
			data.max = newData;
		}
		data.acc += newData;
		++data.countAcc;

		std::cout << "Max " << data.name << " " << data.max << std::endl;
		std::cout << "Min " << data.name << " " << data.min << std::endl;
		std::cout << "Average " << data.name << " " << (data.acc / data.countAcc) << std::endl;
	}

	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую.
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		UpdateData(m_temperature, data.temperature);
		std::cout << "---" << std::endl;
		UpdateData(m_humidity, data.humidity);
		std::cout << "---" << std::endl;
		UpdateData(m_pressure, data.pressure);
		std::cout << "----------------" << std::endl;
	}

	StatsData m_temperature { "Temp" };
	StatsData m_humidity { "Hum" };
	StatsData m_pressure { "Pressure" };
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature()const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity()const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;	
	double m_pressure = 760.0;	
};
