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
        for(int i = 0; i < cap;i++){
            map.push_back({"","","","","",""});
        }
        capacity = cap;
        size = 0;
        maxLoadFactor = 0.75;
    }

    long hashFunc(string cityName){
        long value = 0;
        int i = 0;
        for(auto s : cityName){
            if(s == ' ') {
                i++;
                continue;
            }
            s = tolower(s);
            value += alphabet[(char) s] * (30^i);
            i++;
        }
        return value % capacity;
    }
    void insert(vector<string> cityAttributes){
        int index = hashFunc(cityAttributes[0]);
        if(map[index].empty()){
            map[index] = cityAttributes;
            size++;
        }
        else{
            int currSize = size;
            while(size == currSize){
                index += 1;
                if(index > capacity){

                }
                if(map[index].empty()){
                    size++;
                }
            }

        }
    }

    void resize(){
        for(int i = 0; i < 100; i++){
            map.push_back({"","","","","",""});
        }
        capacity += 100;
    }
    void rehash(){
        resize();
        for(auto vec : map){
            int index = hashFunc(vec[0]);

        }

    }

};


