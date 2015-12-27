#pragma once
#include<string>
#include<iostream>
using namespace std;

class Player {
public:

    static const int MAX_HEALTH = 5; //In effect, the number of times a Character.Attack() can return true before user loses the game.

                                     //Constructors: Deafult and Non-Default
    Player();
    Player(int health, int coordinates);

    //Mutator and accessor functions
    void SetCoord(int Coords[2]);
    int GetCoord(int index) const;
    int GetHealth() const;
    void SetHealth(int health);


private:
    //Data members!
    int health;
    int coordinates[2];
};