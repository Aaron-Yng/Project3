#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

map<char,int> alphabet = {{'a',1},{'b',2},{'c',3},{'d', 4},{'e',5},{'f', 6},{'g',7},
                          {'h',8},{'i', 9},{'j',10},{'k',11},{'l',12},{'m',13},{'n',14},
                          {'o',15},{'p',16},{'q',17},{'r',18},{'s',19},{'t',20},{'u',21},
                          {'v',22},{'w',23},{'x',24},{'y',25},{'z',26}};

//linear probing hash table
class hashMapLinear{
private:

    vector<vector<string>> map;
    int capacity;
    int size;
    double maxLoadFactor;

public:

    hashMapLinear(int cap){
        //creates empty 2d array with cap number of rows
        for(int i = 0; i < cap;i++){
            map.push_back({});
        }
        capacity = cap;
        size = 0;
        maxLoadFactor = 0.75;
    }

    long hashFunc(string cityName){
        long value = 0;
        int i = 0;
        for(auto s : cityName){
            //ignores space in string
            if(s == ' ') {
                i++;
                continue;
            }
            s = tolower(s);
            //gets value from alphabet map corresponding to letter character s
            value += alphabet[(char) s] * (30^i);
            i++;
        }
        return value % capacity;
    }
    void insertHelper(vector<string> cityAttributes, vector<vector<string>> Map){
        //checks if the current capacity exceeds max load factor
        if(size > maxLoadFactor*(double)capacity){
            reHash();
        }
        //hashes based on city name which is in cityAttributes[0]
        int index = hashFunc(cityAttributes[0]);
        if(Map[index].empty()){
            Map[index] = cityAttributes;
            size++;
        }
        else{
            //increases array until empty spot is found
            while(!Map[index].empty()){
                index += 1;
                if(index >= capacity){
                    index = 0;
                }
            }
            Map[index] = cityAttributes;
            size++;

        }
    }

    void insert(vector<string>& attributes){
        insertHelper(attributes,map);
    }

    void reHash(){
        vector<vector<string>> newMap;
        for(int i = 0; i < capacity * 3; i++){
            newMap.push_back({});
        }
        capacity *= 5;
        for(const auto& vec : map){
            insertHelper(vec,newMap);
        }
        map = newMap;
    }

    vector<string> find(const string& city){
        int index = hashFunc(city);

        while(!map[index].empty() and map[index][0] != city){
            index++;
            if(index >= capacity){
                index = 0;
            }
        }
        if(map[index].empty()){
            cout << "Could not find city" << endl;
            return {};
        }
        return map[index];

    }


};


