#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "Location.h"
using namespace std;

class Map {

public:

    //Constructors: Deafult and Non-Default
    Map();
    Map(string filename);


    //Mutator and accessor functions
    vector<vector<Location>>& GetMap();


    //Other member functions
    Location& GetLocation(const Player &oleg);
    bool isValidLocation(int location[2], const Player &oleg);


private:
    //Private helper function
    void LoadFile(string filename);

    //Data member!
    vector<vector<Location>> map;

};