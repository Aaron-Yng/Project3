//
// Created by Aaron Young on 12/1/24.
//

#include "FoodList.h"

FoodList::Food::Food(int _id, string &_name):fdc_id(_id), name(_name){
    cals = 0;
    fat = 0;
    carbs = 0;
    protein = 0;
}

FoodList::Food::Food()
{
    fdc_id = 0;
    name = "";
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


    //populates the foodList vector
    string tempName;
    unsigned int tempID;
    int start;
    int end;
    getline(input, line);
    while(!input.eof()){
        start = line.find('\"') + 1;
        end = line.find('\"', start) - start;
        tempID = stoi(line.substr(start, end));
        //cout << line.substr(start, end) << endl;

        start = line.find('\"', end + start + 3) + 3;
        end = line.find('\"', start) - start;
        tempName = line.substr(start, end);
        //cout << line.substr(start, end) << endl;

        Food newFood(tempID, tempName);
        foodMap.insert({tempID,newFood});

        getline(input, line);
    }
    cout << "Map Populated." << endl;

    input.close();

    path = "../FoodData_Central_branded_food_csv_2024-10-31/food_nutrient.csv";
    input.open(path);

    getline(input, line);
    cout << line << endl;

    getline(input, line);

    int tempNutri;
    int nutriVal;
    while(!input.eof()){
        line = line.substr(line.find('\"', 1) + 3);
        end = line.find('\"');
        tempID = stoi(line.substr(0,end));
        //cout << "fdc_id: " << foodMap[tempID].fdc_id << endl;

        line = line.substr(line.find('\"', 1) + 3);
        end = line.find('\"');
        tempNutri = stoi(line.substr(0,end));

        line = line.substr(line.find('\"', 1) + 3);
        end = line.find('\"');
        nutriVal = stoi(line.substr(0,end));

        switch(tempNutri){
            case(1008):
                foodMap[tempID].cals = nutriVal;
                break;
            case(1003):
                foodMap[tempID].protein = nutriVal;
                break;
            case(1004):
                foodMap[tempID].fat = nutriVal;
                break;
            case(1005):
                foodMap[tempID].carbs = nutriVal;
                break;
        }

        getline(input, line);
    }

    cout << "Nutrients Loaded." << endl;

    for(auto [key,food]: foodMap){
        foodList.push_back(food);
    }
    cout << "List Populated." << endl;

/*
Notes:
    1008: general cals
    1003: protein
    1004: fats
    1005: carbs
*/

}
