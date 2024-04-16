#include <iostream>
#include <vector>
#include <string>
#include <ifstream>

struct city
{
    string name;
    string state;
    int population;
    float area;
    float average_age;
    float average_household_income;
    string climate;
    // Any reccommendations?
    //https://data.census.gov/table/ACSDP5Y2022.DP05?g=040XX00US12$1600000&d=ACS%205-Year%20Estimates%20Data%20Profiles&moe=false
    //The link above is to the data set just for Florida so lmk if u like it also dont download table just view it and make sure to get rid of margin of error
};

class parsingCSV
        {
    private:
        vector<city> cities;
    public:

};

