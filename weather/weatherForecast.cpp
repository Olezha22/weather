#include "weatherForecast.h"


WeatherForecast::WeatherForecast()
    : weather_week_day("Unknown"), weather_month_day(1), weather_month(1),
    weather_temperature(0.0), weather_precipitation(0.0)
{}


WeatherForecast::WeatherForecast(std::string weekDay, int monthDay, int month, double temp, double prec)
    : weather_week_day(weekDay), weather_month_day(monthDay), weather_month(month),
    weather_temperature(temp), weather_precipitation(prec)
{}

WeatherForecast::WeatherForecast(const WeatherForecast& WF)
    : weather_week_day(WF.weather_week_day), weather_month_day(WF.weather_month_day),
    weather_month(WF.weather_month), weather_temperature(WF.weather_temperature),
    weather_precipitation(WF.weather_precipitation)
{}


WeatherForecast::~WeatherForecast()
{}


std::string WeatherForecast::getWeekDay() const {
    return weather_week_day;
}

int WeatherForecast::getMonthDay() const {
    return weather_month_day;
}

int WeatherForecast::getMonth() const {
    return weather_month;
}

double WeatherForecast::getTemperature() const {
    return weather_temperature;
}

double WeatherForecast::getPrecipitation() const {
    return weather_precipitation;
}


void WeatherForecast::setTemperature(double temp) {
    weather_temperature = temp;
}

void WeatherForecast::setPrecipitation(double prec) {
    weather_precipitation = prec;
}


void WeatherForecast::writeTo(std::ostream& os) const {
    os << "Week Day: " << weather_week_day << "\n"
        << "Month Day: " << weather_month_day << "\n"
        << "Month: " << weather_month << "\n"
        << "Temperature: " << weather_temperature << "\n"
        << "Precipitation: " << weather_precipitation << "\n";
}


void WeatherForecast::readFrom(std::istream& is) {
    is >> weather_week_day >> weather_month_day >> weather_month >> weather_temperature >> weather_precipitation;
}


bool WeatherForecast::operator<(const WeatherForecast& WF) const {
    if (weather_month != WF.weather_month)
        return weather_month < WF.weather_month;
    return weather_month_day < WF.weather_month_day;
}

bool WeatherForecast::operator>(const WeatherForecast& WF) const {
    if (weather_month != WF.weather_month)
        return weather_month > WF.weather_month;
    return weather_month_day > WF.weather_month_day;
}


std::ostream& operator<<(std::ostream& os, const WeatherForecast& WF) {
    WF.writeTo(os);
    return os;
}


std::istream& operator>>(std::istream& is, WeatherForecast& WF) {
    WF.readFrom(is);
    return is;
}