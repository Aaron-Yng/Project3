//
// Created by Aaron Young on 12/1/24.
//

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
using namespace std;

class FoodList {
private:
    struct Food {
        unsigned int fdc_id; //unique id of food item
        string name;
        double cals;
        double fat;
        double carbs;
        double protein;

        Food(int _id, string& name);
        Food();
    };
    void heapify_cals(vector<Food>& list, int size, int i);
    void heapify_fat(vector<Food>& list, int size, int i);
    void heapify_carbs(vector<Food>& list, int size, int i);
    void heapify_protein(vector<Food>& list, int size, int i);
    void merge(vector<Food>& sub_list, int left_index, int mid, int right_index, int nutrient);

    unordered_map<int, Food> foodMap; //need to use map in order to retrieve values from food_nutrient.csv

public:
    vector<Food> foodList;
    FoodList();
    void heapSort(vector<Food>& list, int nutrient);
    void mergeSort(vector<Food>& list, int left_index, int right_index, int nutrient);
    void sortFoods();
    void searchFoods();

};

/*
Notes:
    2047: general cals
    2048: specific cals
    1003: protein
    1004: fats
    1005: carbs
*/