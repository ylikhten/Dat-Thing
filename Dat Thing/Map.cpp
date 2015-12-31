#include "Map.h"

// Default Constructor
Map::Map() {
    string filename = "mapu.map";            //Plight of the Vampire Rabbit Game Map
    LoadFile(filename);
}

// Non-default Constructor
Map::Map(string filename) {
    LoadFile(filename);
}


//Mutator and accessor function definitions
Location& Map::GetLocation(const Player &oleg) {
    return map[oleg.GetCoord(0)][oleg.GetCoord(1)];
}

vector<vector<Location>>& Map::GetMap() {
    return map;
}




//Loads file into 3D data member "map," which is a 3-dimensional matrix, essentially.
void Map::LoadFile(string filename) {
    vector <Location> tempRow;
    short tempShort;
    string tempStr;
    char c = 'c';                                                   //Temp Character

    ifstream file(filename);                                        // Opens file at address filename
    if (!file.good()) {                                             // Checks for error loading file
        cerr << "Error loading file. <(>_<)>" << endl;
        exit(1);
    }

    file >> tempShort;                                              // Number of "layers" or "floors" - now rooms
    map.resize(tempShort);
    file >> tempShort;                                              // Number of coloumns
    tempRow.resize(tempShort);
    file.get(c);
    file.get(c);
    c = 'c';

    for (int i = 0; i < map.size(); ++i) {                          // Reads in data to "map"                                                               
        for (int k = 0; k < tempRow.size(); ++k) {
            while (!isspace(c)) {
                if (!file.get(c) || !file.good()) {
                    cout << "End of file" << endl;
                    break;
                }
                if (isalpha(c)) {
                    tempStr.push_back(c);
                    cout << c;                                    //DEBUGGER
                }

            }
            cout << "\t";
            //cout << tempStr << "\t";                              //DEBUGGER
            tempRow.at(k).SetName(tempStr);
            c = 'c';
            tempStr = "";
        }
        map.at(i) = tempRow;
        cout << endl;                                             //DEBUGGER
    }
    file.close();                                                   // Closes file
}

//Checks if given location is invalid - defined by either not being on the map or by being at a NULL space within the map.
bool Map::isValidLocation(int location[2], const Player &oleg) {
 
    if (GetLocation(oleg).GetName() == "FieldA" && (location[0] < 0 || location[0] > map.size() - 1 || location[1] < 0 || location[1] > map.at(0).size() - 1 || map[location[0]][location[1]].GetName() == "N" || map[location[0]][location[1]].GetName() == "NULL")) {
        cout << "Senpai shouldn't listen to Trolls Dx." << endl << "Keep in mind, some paths may not be accessible." << endl << endl;
        cout << "> See a trail heading south " << endl;
        
        return false;
    }
    
        if (location[0] < 0 || location[0] > map.size() - 1 || location[1] < 0 || location[1] > map.at(0).size() - 1 || map[location[0]][location[1]].GetName() == "N" || map[location[0]][location[1]].GetName() == "NULL") {
            cout << "That is not a valid direction, Senpai. Try typing 'look'\nto to orient yourself ;)" << endl;
            return false;
        }
        else if ((int)map.at(oleg.GetCoord(0)).at(oleg.GetCoord(1)).GetNumChar() == 0) {
            return true;
        }
        else if (map.at(oleg.GetCoord(0)).at(oleg.GetCoord(1)).GetChar(0).GetBeaten() == false && map.at(location[0]).at(location[1]).GetNumChar() == 0) {
            cout << "You cannot progress to the next area until you remove \nthe enemy obstacle of this area desu..." << endl;
            return false;
        }
        else if (map.at(oleg.GetCoord(0)).at(oleg.GetCoord(1)).GetChar(0).GetBeaten() == false && map.at(location[0]).at(location[1]).GetChar(0).GetBeaten() == false) {
            cout << "You cannot progress to the next area until you remove \nthe enemy obstacle of this area desu..." << endl;
            return false;
        }
        else
            return true;
    
}
