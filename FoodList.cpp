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

void FoodList::heapify_cals(vector <FoodList::Food> &list, int size, int i) {
    int largest = i;
    int left_index = (2 * i) + 1;
    int right_index = (2 * i) + 2;
    // if left larger
    if(left_index < size && list[left_index].cals > list[largest].cals) {
        largest = left_index;
    }
    // if right larger
    if(right_index < size && list[right_index].cals > list[largest].cals) {
        largest = right_index;
    }
    // if not still root
    if(largest != i) {
        swap(list[i], list[largest]);
        heapify_cals(list, size, largest);
    }
}

void FoodList::heapify_carbs(vector <FoodList::Food> &list, int size, int i) {
    int largest = i;
    int left_index = (2 * i) + 1;
    int right_index = (2 * i) + 2;
    // if left larger
    if(left_index < size && list[left_index].carbs > list[largest].carbs) {
        largest = left_index;
    }
    // if right larger
    if(right_index < size && list[right_index].carbs > list[largest].carbs) {
        largest = right_index;
    }
    // if not still root
    if(largest != i) {
        swap(list[i], list[largest]);
        heapify_carbs(list, size, largest);
    }
}

void FoodList::heapify_fat(vector <FoodList::Food> &list, int size, int i) {
    int largest = i;
    int left_index = (2 * i) + 1;
    int right_index = (2 * i) + 2;
    // if left larger
    if(left_index < size && list[left_index].fat > list[largest].fat) {
        largest = left_index;
    }
    // if right larger
    if(right_index < size && list[right_index].fat > list[largest].fat) {
        largest = right_index;
    }
    // if not still root
    if(largest != i) {
        swap(list[i], list[largest]);
        heapify_fat(list, size, largest);
    }
}

void FoodList::heapify_protein(vector <FoodList::Food> &list, int size, int i) {
    int largest = i;
    int left_index = (2 * i) + 1;
    int right_index = (2 * i) + 2;
    // if left larger
    if(left_index < size && list[left_index].protein > list[largest].protein) {
        largest = left_index;
    }
    // if right larger
    if(right_index < size && list[right_index].protein > list[largest].protein) {
        largest = right_index;
    }
    // if not still root
    if(largest != i) {
        swap(list[i], list[largest]);
        heapify_protein(list, size, largest);
    }
}

void FoodList::heapSort(vector <FoodList::Food>& list, int nutrient) {
    // nutrients: 1 = cals, 2 = fat, 3 = carbs, 4 = protein
    int list_size = list.size();
    // sort by cals
    if(nutrient == 1) {
        for(int i = (list_size / 2) - 1; i >= 0; i--) {
            // building heap
            heapify_cals(list, list_size, i);
            // extract elements from heap
            for(int i = list_size - 1; i > 0; i--) {
                swap(list[0], list[i]);
                heapify_cals(list, i, 0);
            }
        }
    }
    // sort by fat
    if(nutrient == 2) {
        for(int i = (list_size / 2) - 1; i >= 0; i--) {
            // building heap
            heapify_fat(list, list_size, i);
            // extract elements from heap
            for(int i = list_size - 1; i > 0; i--) {
                swap(list[0], list[i]);
                heapify_fat(list, i, 0);
            }
        }
    }
    // sort by carbs
    if(nutrient == 3) {
        for(int i = (list_size / 2) - 1; i >= 0; i--) {
            // building heap
            heapify_carbs(list, list_size, i);
            // extract elements from heap
            for(int i = list_size - 1; i > 0; i--) {
                swap(list[0], list[i]);
                heapify_carbs(list, i, 0);
            }
        }
    }
    // sort by protein
    if(nutrient == 4) {
        for(int i = (list_size / 2) - 1; i >= 0; i--) {
            // building heap
            heapify_protein(list, list_size, i);
            // extract elements from heap
            for(int i = list_size - 1; i > 0; i--) {
                swap(list[0], list[i]);
                heapify_protein(list, i, 0);
            }
        }
    }
}
