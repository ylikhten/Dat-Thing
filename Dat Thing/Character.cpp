#include "Character.h"


// Default Constructor
Character::Character() {
    endurance = 1;
    speed = 1;
    beaten = false;
    name = "Dad";
}

// Non-default Constructor
Character::Character(int endurance, int speed, bool beaten, string Name) {
    this->endurance = endurance;
    this->speed = speed;
    this->beaten = beaten;
    name = Name;
    AdjustName();
}

//MUTATOR / ACCESSOR FUNCTIONS
int Character::GetEndurance() const {
    return endurance;
}
void Character::SetEndurance(int endurance) {
    this->endurance = endurance;
}
int Character::GetSpeed() const {
    return speed;
}
void Character::SetSpeed(int speed) {
    this->speed = speed;
}
bool Character::GetBeaten()const {
    return beaten;
}
void Character::SetBeaten(bool isBeaten) {
    if (beaten)
        beaten = isBeaten;
    else {
        beaten = isBeaten;
        AdjustName();
    }
}
string Character::GetName() const {
    return name;
}
void Character::SetName(string Name) {
    name = Name;
}

// MEMBER FUNCTIONS
bool Character::Attack(Player &oleg) {

    if (name == "Stan") {

        cout << "Stan: Whoa man, I don't want any trouble... What the fu---" << endl;
    }
    else if (name == "Tumblrina") {

        cout << "Tumblrina: Check your privilege you cis pig, these are muh curves!" << endl;

    }
    else if (name == "Fedora") {

        cout << "*tipping intensifies*" << endl;

    }

    srand((int)time);
    int UserTime;
    string UserInput, CorrectResponse;

    for (int i = 0; i < endurance; ++i) {

        int temp = rand() % 3;

        if (temp == 0) {
            cout << "\n\n" << name << " attacks from the left!" << endl;
            CorrectResponse = "right";
        }
        else if (temp == 1) {
            cout << "\n\n" << name << " attacks from the right!" << endl;
            CorrectResponse = "left";
        }
        else {
            cout << "\n\n" << name << " tries to kick you!" << endl;
            CorrectResponse = "jump";
        }

        UserTime = clock();
        getline(cin, UserInput);
        UserInput = CleanUp(UserInput);
        UserTime = clock() - UserTime;

        if (((double)UserTime / CLOCKS_PER_SEC) <= 11 - speed && CorrectResponse == UserInput) {
            cout << "\nACE" << endl;
        }
        else {
            cout << "Senpai you've been hit! Your lanky, undernourished body was not ready for this. Your vision gets cloudy. \nBefore blacking out, you stumble back Home to recupurate.\n";
            oleg.SetHealth(oleg.GetHealth() - 1);
            return true;
        }

    }
    return false;

}

bool Character::Talk(Player &oleg) {
    if (endurance == 100 && beaten) {


        return true;
    }

    return false;
}

string Character::CleanUp(string str) {
    for (int i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void Character::AdjustName() {
    if (beaten && endurance < 100)
        name += "'s body";
}