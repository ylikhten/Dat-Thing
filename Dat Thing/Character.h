#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include <cmath>
class Character {
public:
    //Constructors: Deafult and Non-Default
    Character();
    Character(int endurance, int speed, bool beaten, string Name);

    //Mutator and accessor functions
    int GetEndurance() const;
    void SetEndurance(int endurance);
    int GetSpeed() const;
    void SetSpeed(int speed);
    bool GetBeaten()const;
    void SetBeaten(bool isBeaten);
    string GetName() const;
    void SetName(string Name);

    //Other member functions
    bool Attack(Player &oleg);
    bool Talk(Player &oleg);

private:
    //Private helper functions
    void AdjustName();
    string CleanUp(string str);

    //Data members!
    string name;
    int endurance;
    int speed;
    bool beaten;

};