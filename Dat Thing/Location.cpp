#include "Location.h"


// Default Constructor
Location::Location() {
    //name = "MEH";
    //characters.resize(0);
    //string FlvTxt = "WUT";

}

// Non-default Constructor
Location::Location(string name, short numCharacters) {
    this->name = name;
    characters.resize(numCharacters);

    //if (name == "Lab") {
    //    FlvTxt = "You see a single student doing a programming assignment. Otherwise, the lab is empty, and there is an exit to the north. The student seems to be fatigued from pulling"
    //        "three all-nighters, and his obscene Blood-Coffee content has left him disoriented."
    //        "As it so happens, you find yourself parched and in need of a boost in morale.... This student seems to be an appropriate target...";

    //}
    //else if (name == "Starbucks") {
    //    FlvTxt = "You approach a portrait of an exquisute, green, double-tailed mermaid. It seems to be an outlet of over-priced treats and there is a distinct smell of coffee in the air... "
    //        "This must be where the first victim got his coffee! Well, good, it seems you are getting somewhere. You also note a hallway to the east. "
    //        "Inside the cubic perimeter of the coffee dispensary, you see a woman who seems to be working at this establishment. She seems wise. Better not to feed on her."
    //        "On the other hand, there is a professor sitting at a booth in front of the coffee dispensary, frantically grading exams. He would be a good target! But he does not seem as disoriented as the first opponent...";

    //}
    //else if (name == "HallwayA") {
    //    FlvTxt = "You look around the hallway... It is barren -- no one to feed upon here. The next hallway is north, and your hunger has yet to be satiated.";

    //}
    //else if (name == "HallwayB") {

    //    FlvTxt = "In front of you there is a student milling around to your east... The direction of the exit! The fool! Does he not know the fate that will befall him?!"
    //        " You must rid the path of this nuisance, but be careful. He seems to be a more qualified foe than the rest.";

    //}
    //else if (name == "Exit") {
    //    FlvTxt = "You see the exit! The glorious exit! But what is this... Someone is blocking the exit, and what is worse, he looks to be a powerful opponent. You prepare yourself for an arduous battle.";

    //}

}

//MUTATOR / ACCESSOR FUNCTIONS
string Location::GetName() const {
    return name;
}

void Location::SetName(string name) {
    this->name = name;

    //if (name == "Lab") {
    //    FlvTxt = "You see a single student doing a programming assignment. Otherwise, the lab is empty, and there is an exit to the north. The student seems to be fatigued from pulling"
    //        " three all-nighters, and his obscene Blood-Coffee content has left him disoriented."
    //        " As it so happens, you find yourself parched and in need of a boost in morale.... This student seems to be an appropriate target..."
    //        " You should choose to 'attack' any foes that may be present.";
    //}
    //else if (name == "Starbucks") {
    //    FlvTxt = "You approach a portrait of an exquisute, green, double-tailed mermaid. It seems to be an outlet of over-priced treats and there is a distinct smell of coffee in the air... "
    //        "This must be where the first victim got his coffee! Well, good, it seems you are getting somewhere. You also note a hallway to the east. "
    //        "Inside the cubic perimeter of the coffee dispensary, you see a woman working at this establishment. She seems wise. Better not to feed on her. "
    //        "On the other hand, there is a professor sitting at a booth in front of the coffee dispensary, frantically grading exams. He would be a good target! But he does not seem as disoriented as the first opponent...";
    //}
    //else if (name == "HallwayA") {
    //    FlvTxt = "You look around the hallway... It is barren -- no one to feed upon here. The next hallway is north, and your hunger has yet to be satiated.";
    //}
    //else if (name == "HallwayB") {
    //    FlvTxt = "In front of you there is a student milling around to your east... The direction of the exit! The fool! Does he not know the fate that will befall him?!"
    //        " You must rid the path of this nuisance, but be careful. He seems to be a more qualified foe than the rest.";
    //}
    //else if (name == "Exit") {
    //    FlvTxt = "You see the exit! The glorious exit! But what is this... Someone is blocking the exit, and what is worse, he looks to be a powerful opponent. You prepare yourself for an arduous battle.";
    //}
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
void Location::Look() {
    cout << Normalize(FlvTxt) << endl;
    for (int i = 0; i < characters.size(); ++i)
        cout << characters.at(i).GetName() << " is in the " << GetName();
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
    if (characters.at(0).GetBeaten()) {
        FlvTxt = "You turn your attention to the wise woman. She tells you some profound advice... \n" +
            characters.at(1).GetName() + ": I hear tales of a cave not far from here. It is said to house the others of your kind. If you make it out of here alive, follow the 'M' on the mountain. It will guide to home!";
        cout << Normalize(FlvTxt) << endl;
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