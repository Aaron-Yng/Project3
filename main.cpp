#include <iostream>
#include <string>
#include "hashTable.h"
#include "parsingCSV.h"
#include <vector>
using namespace std;

//group 50: Julio Arboleda, Carmen Cruz Arana, Graciela Strand


vector<string> citySearcher(string cityName){
    //RETRIEVAL
    //this is where we would have to hash the cityname and find it in the hash table
    //save all the data in the following vector so I can print it out and set it aside for ranking
    vector<string> data;
    cout << endl<< cityName << endl; //data[0]
    cout << "State: " << endl; //data[1]
    cout << "Population: " << endl; //data[2]
    cout << "Population Density: " << endl; //data[3]
    cout << "Median Age: " << endl; //data[4]
    cout << "Average Household Size: " << endl; //data[5]

    return data;
}


void menuBasic(){
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
        citySearcher(cityName);
        menuBasic();
    }
    else if (option == "2"){
        cout << "1 - Rank by Population" << endl;
        cout << "2 - Rank by Density" << endl;
        cout << "3 - Rank by Age" << endl;
        cout << "4 - Rank by Household Size" << endl;
        cin >> option;
        //rank(option)

    }
    else if (option == "3"){
        exit(1);
    }
    else{
        cout << "invalid selection :(" << endl;
        menuBasic();
    }
}

void rank(string option){
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
        menuBasic();
    }
}

int main() {
    hashMapLinear map(10);
    cout << "Welcome to CITY SEARCHER!\nThis program will generate numerical demographical information for any USA city"<< endl;
    cout << "What is your name?" << endl;
    string userName;
    cin >> userName;
    cout << "Hi there " << userName << "!" << endl;
    cout << "Enter the name of a city: " << endl;
    string cityName;
    cin >> cityName;
    citySearcher(cityName);
    cout << "Enter the name of another city: " << endl;
    cin >> cityName;
    citySearcher(cityName);
    menuBasic();


    return 0;
}
