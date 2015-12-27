#pragma once
#include "Character.h"
#include <string>
#include <vector>
using namespace std;

class Location {
public:
    static const int MAX_CHR = 60;                  // Used in Normalize to determine maximum size of a single line of text on the console.

                                                    //Constructors: Deafult and Non-Default
    Location();
    Location(string name, short numCharacters);

    //Mutator and accessor functions
    string GetName() const;
    void SetName(string name);
    short GetNumChar() const;                       //returns size of characters vector... AKA the # of characters at a location
    void SetNumChar(short numCharacters);           //resizes characters vector
    Character& GetChar(int index);

    //Other member functions
    void Look();
    void Talk();
    void AddChar(Character character);
    string Normalize(string str);

private:
    //Data members!
    string name;
    vector<Character> characters;
    string FlvTxt;                                  //FLAVAH TEXT!
};