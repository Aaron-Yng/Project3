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
    while(!cityInfo.eof()){
        getline(cityInfo,line);
        stringstream s(line);
        while(getline(s,attribute,',')){
            attributes.push_back(attribute);
        }
        map.insert(attributes);
    }
    //Done
}

