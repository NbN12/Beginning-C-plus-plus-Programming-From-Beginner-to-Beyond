// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
            },
        },
            { "Argentina", {
                { "Buenos Aires", 3010000, 723.77 }
            }
        },
    }
    };
    const int total_width{ 80 };
    const int country_width{ 25 };
    const int city_width{ 25 };
    const int population_width{ 15 };
    const int price_width{ 15 };
    auto title_len = tours.title.length();
    std::cout << std::setw(total_width)
              << std::setfill('=') << ""
              << std::endl << std::setfill(' ') << std::endl;
    
    std::cout << std::setw((total_width - title_len) / 2) << ""
              << tours.title
              << std::endl << std::endl;

    std::cout << std::left << std::setw(country_width) << "Country" 
              << std::left << std::setw(city_width) << "City"
              << std::right << std::setw(population_width) << "Population"
              << std::right << std::setw(price_width) << "Price" << std::endl;

    std::cout << std::setfill('-') << std::setw(total_width) << "" << std::endl;
    std::cout << std::setfill(' ') << std::fixed << std::setprecision(2);

    for (auto country : tours.countries) {   // loop through the countries

        std::cout << std::setw(country_width) << std::left << country.name << std::endl;

        for (auto city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(country_width) << "" << std::setw(city_width) << std::left << city.name
                << std::setw(population_width) << std::right << city.population
                << std::setw(price_width) << std::right << city.cost
                << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}