//
// Created by Aaron Young on 12/1/24.
//

#include "FoodList.h"

FoodList::Food::Food(int &_id, string &_name):fdc_id(_id), name(_name){
    cals = 0;
    fat = 0;
    carbs = 0;
    protein = 0;
}
