#pragma once
#include<iostream>
#include<string>

class WeatherForecast
{
private:
	std::string weather_week_day;
	int weather_month_day;
	int weather_month;
	double weather_temperature;
	double weather_precipitation;

public:
	WeatherForecast();
	WeatherForecast(std::string weekDay, int monthDay, int month, double temp, double prec);
	WeatherForecast(const WeatherForecast& WF);
	~WeatherForecast();


	std::string getWeekDay() const;
	int getMonthDay() const;
	int getMonth() const;
	double getTemperature() const;
	double getPrecipitation() const;

	void setTemperature(double temp);
	void setPrecipitation(double prec);

	void writeTo(std::ostream& os) const;
	void readFrom(std::istream& is);

	bool operator<(const WeatherForecast& WF) const;
	bool operator>(const WeatherForecast& WF) const;
};

std::ostream& operator<<(std::ostream& os, const WeatherForecast& WF);
std::istream& operator>>(std::istream& is, WeatherForecast& WF);