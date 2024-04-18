#include <iostream>
#include "hashTable.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

vector<string> parseCSV(hashMapLinear map){
    fstream cityInfo;
    string line, attribute;
    vector<string> attributes;
    cityInfo.open("uscities.csv",ios::in);
    getline(cityInfo, line);
    while(!cityInfo.eof()){
        int iteration = 0;
        getline(cityInfo,line);
        stringstream s(line);
        while(getline(s,attribute,',')){
            if(iteration == 0 || iteration == 1 || iteration == 6 || iteration == 7 || iteration == 12 || iteration == 13)
                attributes.push_back(attribute);
            iteration++;
        }
        map.insert(attributes);
    }
}

