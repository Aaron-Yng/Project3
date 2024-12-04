//
// Created by Aaron Young on 12/1/24.
//

#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include "FoodList.h"

using namespace std;

int main() {
    //stuff here
    FoodList foods;
    string sortAlg = "heap";
    int command;

    cout << "Welcome to NutriList!" << endl;

    while(true){
        cout << R"(
Options:
1. Sort Foods
2. Search Foods
3. Exit

Choose a command (1-3): )";
        cin >> command;

        switch(command){
            case(1):
                foods.sortFoods();
                break;
            case(2):
                break;
        }

        if(command == 3){
            cout << "Thank you for using NutriList!";
            break;
        }

    }
}
