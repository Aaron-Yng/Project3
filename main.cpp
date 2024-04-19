#include <iostream>
#include <string>
#include <vector>
#include "parsingCSV.h"
#include "hashTable.h"

using namespace std;

//group 50: Julio Arboleda, Carmen Cruz Arana, Graciela Strand



vector<string> citySearcher(string cityName, hashMapLinear& myMap){
    //RETRIEVAL
    vector<string> data;
    data = myMap.find(cityName);
//return if data is empty
//    if(data.empty())
//        return {};
    if (!data.empty() ){
        cout << endl<< cityName << endl; //data[0]
        cout << "State: " << data[1] << endl;
        cout << "Population: " << data [2] << endl;
        cout << "Population Density: " << "data[3]" << endl;
        cout << "Average Household Size: " << data[4] << endl;
        cout << "Median Age: " << data[5] <<  endl;

    }
    pair<int, string> dataPairs;
    dataPairs.first = stoi(data[2]);
    dataPairs.second = cityName;
    //insert population into pop heap
    dataPairs.first = stoi(data[3]);
    //insert pop density into den heap
    dataPairs.first = stoi(data[4]);
    //insert hhsize into size heap
    dataPairs.first = stoi(data[5]);
    //insert median age into age heap

    return data;
}

void Rank(string option, hashMapLinear& myMap){
    int counter = 1;
    if (option == "1"){
        cout << "Population Ranking (greatest to least)" << endl;
        //for population in all cities, cout << counter << city name << population, counter ++
    }
    else if (option == "2"){
        cout << "Population Density Ranking (greatest to least)" << endl;
    }
    else if (option == "3"){
        cout << "Median Age Ranking (greatest to least)" << endl;
    }
    else if (option == "4"){
        cout << "Average Household Size Ranking (greatest to least)" << endl;
    }
    else{
        cout << "invalid selection :(" << endl;
        //menuBasic(myMap);
    }
}

void menuBasic(hashMapLinear& myMap){
    cout << "Pick from the following options: " << endl;
    cout << "1 - Search another city" << endl;
    cout << "2 - Rank Cities" << endl;
    cout << "3 - end" << endl;
    string option;
    string cityName;
    cin >> option;
    if (option == "1") {
        cout << "Enter the name of another city: " << endl;
        cin >> cityName;
        citySearcher(cityName, myMap);
        menuBasic(myMap);
    }
    else if (option == "2"){
        cout << "1 - Rank by Population" << endl;
        cout << "2 - Rank by Density" << endl;
        cout << "3 - Rank by Age" << endl;
        cout << "4 - Rank by Household Size" << endl;
        cin >> option;
        Rank(option, myMap);

    }
    else if (option == "3"){
        exit(1);
    }
    else{
        cout << "invalid selection :(" << endl;
        menuBasic(myMap);
    }
}



int main() {
    //for line in data set, call parse function
    hashMapLinear LinearMap(10);
    parseCSV(LinearMap);

    cout << "Welcome to CITY SEARCHER!\nThis program will generate numerical demographical information for any USA city"<< endl;
    cout << "What is your name?" << endl;
    string userName;
    cin >> userName;
    cout << "Hi there " << userName << "!" << endl;
    cout << "Enter the name of a city: " << endl;
    string cityName;
    //uses first word of cityName
    getline(cin,cityName);
    cout << cityName << endl;
    citySearcher(cityName, LinearMap);
    cout << "Enter the name of another city: " << endl;
    cin >> cityName;
    citySearcher(cityName, LinearMap);
    menuBasic(LinearMap);


    return 0;
}
