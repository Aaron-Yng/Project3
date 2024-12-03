//
// Created by Aaron Young on 12/1/24.
//

#include "FoodList.h"
#include <filesystem>

FoodList::Food::Food(int _id, string &_name):fdc_id(_id), name(_name){
    cals = 0;
    fat = 0;
    carbs = 0;
    protein = 0;
}

FoodList::FoodList()
{

    ifstream input;
    string line;
    string path = "../FoodData_Central_branded_food_csv_2024-10-31/food.csv";
    input.open(path);

    if(!input.is_open()){
        cout << "Error: File Not Open";
    }

    getline(input, line);
    cout << line << endl;

    string tempName;
    unsigned int tempID;
    int start;
    int end;

    getline(input, line);
    while(!input.eof()){
        start = line.find('\"') + 1;
        end = line.find('\"', start) - start;

        cout << line.substr(start, end) << endl;
        tempID = stoi(line.substr(start, end));

        start = line.find('\"', end + start + 3) + 3;
        end = line.find('\"', start) - start;

        cout << line.substr(start, end) << endl;
        tempName = line.substr(start, end);

        Food newFood(tempID, tempName);
        foodList.push_back(newFood);

        getline(input, line);
    }
}
