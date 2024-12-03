//
// Created by Aaron Young on 12/1/24.
//

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
using namespace std;

class FoodList {
private:
    struct Food {
        unsigned int fdc_id; //unique id of food item
        string name;
        unsigned int cals;
        unsigned int fat;
        unsigned int carbs;
        unsigned int protein;

        Food(int _id, string& name);
        Food();
    };

    vector<Food> foodList;
    unordered_map<int, Food> foodMap; //need to use map in order to retrieve values from food_nutrient.csv

public:
    FoodList();

};

/*
Notes:
    2047: general cals
    2048: specific cals
    1003: protein
    1004: fats
    1005: carbs
*/