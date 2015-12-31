#include "Location.h"


// Default Constructor
Location::Location() {
    name = "MEH";
    characters.resize(0);
    string FlvTxt = "WUT";

}

// Non-default Constructor
Location::Location(string name, short numCharacters) {
    this->name = name;
    characters.resize(numCharacters);

    if (name == "Home") {
       
        FlvTxt = "";
    }
    else if (name == "FieldA") {

    }
    else if (name == "ClifA") {
 
    }
    else if (name == "ClifB") {

    }
    else if (name == "ClifC") {

    }
    else if (name == "Town") {

    }
    else if (name == "Gorge") {

    }
    else if (name == "FieldB") {

    }
    else if (name == "Marsh") {

    }
    else if (name == "CaveA") {

    }
    else if (name == "CaveB") {

    }
    else if (name == "Goal") {

    }



}

//MUTATOR / ACCESSOR FUNCTIONS
string Location::GetName() const {
    return name;
}

void Location::SetName(string name) {
    this->name = name;

    if (name == "Home") {

        FlvTxt = "";
    }
    else if (name == "FieldA") {

    }
    else if (name == "ClifA") {

    }
    else if (name == "ClifB") {

    }
    else if (name == "ClifC") {

    }
    else if (name == "Town") {

    }
    else if (name == "Gorge") {

    }
    else if (name == "FieldB") {

    }
    else if (name == "Marsh") {

    }
    else if (name == "CaveA") {

    }
    else if (name == "CaveB") {

    }
    else if (name == "Goal") {

    }

}

short Location::GetNumChar() const {
    return characters.size();
}

void Location::SetNumChar(short numCharacters) {
    characters.resize(numCharacters);
}

Character& Location::GetChar(int index) {
    if (index >= 0 && index < characters.size())
        return characters.at(index);
}

//Member functions
void Location::Text() {
    int count = 0;
    


}
void Location::Look() {
    //cout << (FlvTxt) << endl;


    for (int i = 0; i < characters.size(); ++i)
        cout << characters.at(i).GetName() << " is in the area";
    if (characters.size() > 0) {
        if (characters.size() > 1) {
            cout << "\nAvailable commands:\n'attack'\n'move'\n'look'\n'talk'\n";
        }
        else {
            cout << "\nAvailable commands:\n'attack'\n'move'\n'look'\n";
        }
    }
}
void Location::Talk() {
    if (name == "FieldA") {
        FlvTxt = "Troll: You look like you're on a quest m8. I suggest going east about here, it's a faster route.";
        cout << Normalize(FlvTxt) << endl;

        //cout << "> See a trail heading south and another trail heading north " << endl;
        //cout << "> ";
        
    }
    else if (name == "ClifA") {
        FlvTxt = "Fit Bro: Wat you looking at faggot... WANNA FIGHT?!";
        cout << Normalize(FlvTxt) << endl;
        cout << "< He will not...";

    }
    else if (name == "ClifB") {
        FlvTxt = "Stan: What a nice day for a hike.";
        cout << Normalize(FlvTxt) << endl;
        
    }
    else if (name == "ClifC") {
        FlvTxt = "An Hero: Someone in town called me a plebeian and told me I had a weak jaw line. I’m going to end it! ;-;";
        cout << Normalize(FlvTxt) << endl;
        cout << "> Realize there is a town nearby. \n>Must be going right way. Continue north to town." << endl;

    }
    else if (name == "Town") {

    }
    else if (name == "Gorge") {

    }
    else if (name == "FieldB") {

    }
    else if (name == "Marsh") {

    }
    else if (name == "CaveA") {

    }
    else if (name == "CaveB") {

    }
    else if (name == "Goal") {

    }



    else {
        cout << "\nPerhaps you should feed on your opponent first..." << endl;
    }

}
void Location::AddChar(Character character) {
    characters.push_back(character);
}

string Location::Normalize(string str) {
    int counter = 0;
    str.insert(0, "\n");
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == (int)' ' && counter >= MAX_CHR) {
            str[i] = '\n';
            counter = 0;
        }
        counter++;
    }
    str.append("\n");
    return str;
}