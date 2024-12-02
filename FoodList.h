//
// Created by Aaron Young on 12/1/24.
//

#pragma once

#include <string>
#include <vector>
using namespace std;

class FoodList {
private:

public:
    struct Food {
        unsigned int fdc_id; //unique id of food item
        string name;
        unsigned int cals;
        unsigned int fat;
        unsigned int carbs;
        unsigned int protein;

        Food(int& _id, string& name);
    };

};

/*
Notes:
    2047: general cals
    2048: specific cals
    1003: protein
    1004: fats
    1005: carbs
*/