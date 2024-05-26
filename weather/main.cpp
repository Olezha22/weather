#include "weatherForecast.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <set>

int main() {

    WeatherForecast WF;

    std::ifstream fin("weatherForecast.txt");

    std::vector<WeatherForecast> forecasts;

    std::copy(std::istream_iterator<WeatherForecast>(fin),
        std::istream_iterator<WeatherForecast>(),
        std::back_inserter(forecasts));

    fin.close();

    std::sort(forecasts.begin(), forecasts.end());
    std::copy(forecasts.begin(), forecasts.end(), std::ostream_iterator<WeatherForecast>(std::cout, "\n"));


    int givenMonth = 6;

    double totalPrecipitation = std::accumulate(forecasts.begin(), forecasts.end(), 0.0,
        [givenMonth](double sum, const WeatherForecast& wf) {
            return (wf.getMonth() == givenMonth) ? sum + wf.getPrecipitation() : sum;
        });

    int daysWithoutPrecipitation = std::count_if(forecasts.begin(), forecasts.end(),
        [givenMonth](const WeatherForecast& wf) {
            return (wf.getMonth() == givenMonth) && (wf.getPrecipitation() == 0);
        });

    std::cout << "Total precipitation in month " << givenMonth << ": " << totalPrecipitation << " mm" << std::endl;
    std::cout << "Number of days without precipitation in month " << givenMonth << ": " << daysWithoutPrecipitation << std::endl;

    std::vector<WeatherForecast> forecastsWithoutPrecipitation;
    std::copy_if(forecasts.begin(), forecasts.end(), std::back_inserter(forecastsWithoutPrecipitation),
        [](const WeatherForecast& wf) { return wf.getPrecipitation() == 0; });

    std::sort(forecastsWithoutPrecipitation.begin(), forecastsWithoutPrecipitation.end(),
        [](const WeatherForecast& wf1, const WeatherForecast& wf2) {
            return wf1.getTemperature() < wf2.getTemperature();
        });

    std::cout << "\nColdest day without precipitation: \n" << forecastsWithoutPrecipitation.front() << std::endl;
    std::cout << "Warmest day without precipitation: \n" << forecastsWithoutPrecipitation.back() << std::endl;


    std::string givenDayOfWeek = "Monday";
    std::set<double> uniqueTemperatures;

    std::for_each(forecasts.begin(), forecasts.end(),
        [&uniqueTemperatures, &givenDayOfWeek](const WeatherForecast& wf) {
            if (wf.getWeekDay() == givenDayOfWeek) {
                uniqueTemperatures.insert(wf.getTemperature());
            }
        });

    std::cout << "\nUnique temperatures for " << givenDayOfWeek << ": ";
    std::copy(uniqueTemperatures.begin(), uniqueTemperatures.end(),
        std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}