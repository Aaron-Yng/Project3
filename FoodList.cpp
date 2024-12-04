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
    //cout << line << endl;


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
    //cout << "Map Populated." << endl;

    input.close();

    path = "../FoodData_Central_branded_food_csv_2024-10-31/food_nutrient.csv";
    input.open(path);

    getline(input, line);
    //cout << line << endl;

    getline(input, line);

    int tempNutri;
    double nutriVal;
    while(!input.eof()){
        line = line.substr(line.find('\"', 1) + 3);
        end = line.find('\"');
        tempID = stoi(line.substr(0,end));
        //cout << "fdc_id: " << foodMap[tempID].fdc_id << endl;

        line = line.substr(line.find('\"', 1) + 3);
        end = line.find('\"');
        tempNutri = stoi(line.substr(0,end));
        //cout << "nutrient: " << tempNutri << endl;

        line = line.substr(line.find('\"', 1) + 3);
        end = line.find('\"');
        nutriVal = stod(line.substr(0,end));
        //cout << "amount: " << nutriVal << endl << endl;

        switch(tempNutri){
            case(1062):
            case(2047):
            case(2048):
            case(1008):
                foodMap[tempID].cals = nutriVal;
                break;
            case(1053):
            case(1003):
                foodMap[tempID].protein = nutriVal;
                break;
            case(1004):
                foodMap[tempID].fat = nutriVal;
                break;
            case(1005):
            case(1050):
            case(1072):
            case(2039):
                foodMap[tempID].carbs = nutriVal;
                break;
        }

        getline(input, line);
    }

    //cout << "Nutrients Loaded." << endl;

    for(auto [key,food]: foodMap){
        foodList.push_back(food);
    }
    //cout << "List Populated." << endl;

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
    int list_size = static_cast<int>(list.size());
    // sort by cals
    if(nutrient == 1) {
        for(int i = (list_size / 2) - 1; i >= 0; i--) {
            // building heap
            heapify_cals(list, list_size, i);
        }
        // extract elements from heap
        for(int i = list_size - 1; i > 0; i--) {
            swap(list[0], list[i]);
            heapify_cals(list, i, 0);
        }
    }
    // sort by fat
    if(nutrient == 2) {
        for(int i = (list_size / 2) - 1; i >= 0; i--) {
            // building heap
            heapify_fat(list, list_size, i);
        }
        // extract elements from heap
        for(int i = list_size - 1; i > 0; i--) {
            swap(list[0], list[i]);
            heapify_fat(list, i, 0);
        }
    }
    // sort by carbs
    if(nutrient == 3) {
        for(int i = (list_size / 2) - 1; i >= 0; i--) {
            // building heap
            heapify_carbs(list, list_size, i);
        }
        // extract elements from heap
        for(int i = list_size - 1; i > 0; i--) {
            swap(list[0], list[i]);
            heapify_carbs(list, i, 0);
        }
    }
    // sort by protein
    if(nutrient == 4) {
        for(int i = (list_size / 2) - 1; i >= 0; i--) {
            // building heap
            heapify_protein(list, list_size, i);
        }
        // extract elements from heap
        for(int i = list_size - 1; i > 0; i--) {
            swap(list[0], list[i]);
            heapify_protein(list, i, 0);
        }
    }
}

void FoodList::merge(vector<FoodList::Food>& sub_list, int left_index, int midpoint, int right_index, int nutrient) {
    int left_size = midpoint - left_index + 1;
    int right_size = right_index - midpoint;
    // temporary vectors will end up needing O(N) space complexity
    vector<Food> left_list(left_size), right_list(right_size);
    int i, j;
    for(i=0; i < left_size; i++) {
        left_list[i] = sub_list[left_index + i];
    }
    for(j=0; j < right_size; j++) {
        right_list[j] = sub_list[midpoint + 1 + j];
    }
    i = 0;
    j = 0;
    int k = left_index;
    // merge vectors back
    // nutrients: 1 = cals, 2 = fat, 3 = carbs, 4 = protein
    if(nutrient == 1) {
        while(i < left_size && j < right_size) {
            if(left_list[i].cals <= right_list[j].cals) {
                sub_list[k] = left_list[i];
                i++;
            } else {
                sub_list[k] = right_list[j];
                j++;
            }
            k++;
        }
    } else if(nutrient == 2) {
        while(i < left_size && j < right_size) {
            if(left_list[i].fat <= right_list[j].fat) {
                sub_list[k] = left_list[i];
                i++;
            } else {
                sub_list[k] = right_list[j];
                j++;
            }
            k++;
        }
    } else if(nutrient == 3) {
        while(i < left_size && j < right_size) {
            if(left_list[i].carbs <= right_list[j].carbs) {
                sub_list[k] = left_list[i];
                i++;
            } else {
                sub_list[k] = right_list[j];
                j++;
            }
            k++;
        }
    } else if(nutrient == 4) {
        while(i < left_size && j < right_size) {
            if(left_list[i].protein <= right_list[j].protein) {
                sub_list[k] = left_list[i];
                i++;
            } else {
                sub_list[k] = right_list[j];
                j++;
            }
            k++;
        }
    }
    // copy rest of elements
    while(i < left_size) {
        sub_list[k] = left_list[i];
        k++;
        i++;
    }
    while(j < right_size) {
        sub_list[k] = right_list[j];
        k++;
        j++;
    }
}

void FoodList::mergeSort(vector<FoodList::Food>& list, int left_index, int right_index, int nutrient) {
    if(left_index < right_index) {
        int midpoint = left_index + ((right_index - left_index) / 2);
        // sort both halves
        mergeSort(list, left_index, midpoint, nutrient);
        mergeSort(list, midpoint + 1, right_index, nutrient);
        // merge halves
        merge(list, left_index, midpoint, right_index, nutrient);
    }
}

void FoodList::sortFoods()
{
    int nutrient = 0;
    cout << R"(Select a nutrient to sort by:
1. Calories
2. Fat
3. Carbohydrates
4. Protein

Selection (1-4): )";
    cin >> nutrient;

    string nutriString;
    switch(nutrient){
        case(1):
            nutriString = "calories";
            break;
        case(2):
            nutriString = "fat";
            break;
        case(3):
            nutriString = "carbs";
            break;
        case(4):
            nutriString = "protein";
            break;
    }

    cout << endl;

    int sortAlg = 0;
    cout << R"(
Select a sorting algorithm:
1. Heap Sort
2. Merge Sort

Selection (1-2): )";
    cin >> sortAlg;


    if(sortAlg == 1){
        cout << "Sorting by " << nutriString << " using heap sort..." << endl;

        // use chrono to find time before and after this function call then print out time
        auto start = chrono::system_clock::now();

        heapSort(foodList, nutrient);

        auto end = chrono::system_clock::now();
        cout << "Heap Sort Time Elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milliseconds" << endl;
    }

    // call merge sort with list from 0 to list size - 1
    if(sortAlg == 2) {
        cout << "Sorting by " << nutriString << " using merge sort..." << endl;

        auto start = chrono::system_clock::now();

        mergeSort(foodList, 0, static_cast<int>(foodList.size()) - 1, nutrient);

        auto end = chrono::system_clock::now();
        cout << "Merge Sort Time Elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milliseconds" << endl;
    }

    int display;
    cout << R"(
Display Options:
1. Display top ten foods.
2. Display bottom ten foods.

Selection (1-2): )";
    cin >> display;

    cout << endl;

    int size = foodList.size();
    if(display == 2){
        cout << "Bottom ten foods" << endl;
        for(int i = 1; i < 11; i++){
            cout << i << ". " << foodList[i].name << endl;
            cout << "FDC_ID: " << foodList[i].fdc_id << endl;
            cout << "Calories: " << foodList[i].cals << endl;
            cout << "Fat: " << foodList[i].fat << endl;
            cout << "Carbs: " << foodList[i].carbs << endl;
            cout << "Protein: " << foodList[i].protein << endl << endl;
        }
    } else if(display == 1){
        cout << "Top ten foods:" << endl;
        for(int i = 1; i < 11; i++){
            cout << i << ". " << foodList[size - i].name << endl;
            cout << "FDC_ID: " << foodList[size - i].fdc_id << endl;
            cout << "Calories: " << foodList[size - i].cals << endl;
            cout << "Fat: " << foodList[size - i].fat << endl;
            cout << "Carbs: " << foodList[size - i].carbs << endl;
            cout << "Protein: " << foodList[size - i].protein << endl << endl;
        }
    }
}

void FoodList::searchFoods()
{
    int id;
    cout << "Enter a valid fdc_id: ";
    cin >> id;

    cout << endl;

    if(!foodMap.count(id)){
        cout << "Error: Invalid ID" << endl;
        return;
    }

    Food temp = foodMap.find(id)->second;

    cout << "Name: " << temp.name << endl;
    cout << "FDC_ID: " << temp.fdc_id << endl;
    cout << "Calories: " << temp.cals << endl;
    cout << "Fat: " << temp.fat << endl;
    cout << "Carbs: " << temp.carbs << endl;
    cout << "Protein: " << temp.protein << endl << endl;
}