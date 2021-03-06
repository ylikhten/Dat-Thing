#include <iostream>
#include <conio.h>
#include "Map.h"
using namespace std;

const int MAX_CHR = Location::MAX_CHR;

void Move( Player &oleg, Map &map);
string CleanUp(string str);
string Normalize(string str);
string Cont(Map &map, Player &Oleg);

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


int main() {

    int StartCoord[2] = { 3, 0 };
    string action;
    string toPrint;
    int counter = 0;

    Map map("mapu.map");
    Player Oleg;


    
    Character Dad; //1
    Character Troll(100, 10, true, "Troll"); //2
    Character Nazi(1, 1, false, "Grammar Nazi"); //3
    Character Bro(1, 1, false, "Fit Bro");    //4
    Character Fedora(1, 1, false, "Fedora"); //5
    Character Stan(1, 1, false, "Stan");   //6
    Character Oppai(100, 10, true, "Oppai Chan");    //7
    Character Hero(100, 10, true, "An Hero"); //8 
    Character Tsun(100, 10, true, "Tsundere Master Race");   //9
    Character Fuccboi(100, 10, true, "fuccboi");    //10
    Character Tumbl(1, 1, false, "Tumblrina"); //11
    Character Shitlord(1, 1, false, "Shitlord");   //12



    map.GetMap()[3][0].AddChar(Dad);  //1
    map.GetMap()[3][1].AddChar(Troll);   //2
    map.GetMap()[2][0].AddChar(Nazi);   //3
    map.GetMap()[4][1].AddChar(Bro);    //4
    map.GetMap()[1][0].AddChar(Fedora);   //5
    map.GetMap()[4][2].AddChar(Stan);  //6
    map.GetMap()[1][1].AddChar(Oppai);    //7
    map.GetMap()[4][3].AddChar(Hero);   //8
    map.GetMap()[1][2].AddChar(Tsun);  //9
    map.GetMap()[3][3].AddChar(Fuccboi);    //10
    map.GetMap()[2][3].AddChar(Tumbl);   //11
    map.GetMap()[1][3].AddChar(Shitlord);  //12



    //Gameplay stuff
    cout << "***********Kawaifu Quest***********" << endl << endl;

    string waifu;
    cout << "> Wake up next to favorite daki of (enter Waifu's name): ";
    cin >> waifu;
    cin.ignore();

    cout << "> Go to browse the internets. " << endl;
    cout << "> Someone calls " << waifu << " shit" << endl;


    int count = 0;
    while (!map.GetMap()[1][3].GetChar(0).GetBeaten()) {

            //Cont(map, Oleg);
        
        if (map.GetLocation(Oleg).GetName() == "Home" && count == 0) {
            cout << "> \"your waifu a shit,\" he says. " << endl << "> ohItsOn.jpg " << endl << "> prepare to travel to the ends of the earth to find this guy and... beat him up " << endl;
            cout << "> Suddenly, Dad busts in shouting and shit " << endl;
            cout << endl << "Dad: I'm tired of you being such a pussy! Get off your damn computer! " << endl << endl;
            cout << "> Oh shit " << endl << "> Better 'attack' this faggot " << endl;
            count = 1;

        }
        else if (map.GetLocation(Oleg).GetName() == "FieldA" && count == 1) {

            cout << "> Be me. Be in a field. \n> Some fag meandering about.\n> Should probably 'talk' to him " << endl;
            count = 2;

        }
        else if (map.GetLocation(Oleg).GetName() == "ClifA" && count == 2){  

            cout << "> Walk for fucking ages... Then finally on top of a cliff \n> spot guy doing pull ups from a tree branch \n> go up to see if he will disclose his secrets to dat pump" << endl;
            count = 3;
        
        }
        else if (map.GetLocation(Oleg).GetName() == "ClifB" && count == 3){

            cout << "> See some guy just on a hike. \n>Aaaah what a faggot! Better give him a piece of my mind!" << endl;

            count = 4;
        
        }
        else if (map.GetLocation(Oleg).GetName() == "ClifC" && count == 4){

            cout << "> There's a guy standing at the edge of the cliff \n> He seems knowledgeable; better talk to him" << endl;
            count = 5;
        }
        else if (map.GetLocation(Oleg).GetName() == "Town" && count == 5) {
            cout << "> Hike down the mountain and head into urban landscape \n> See a skelly mode smoking a cigarette� \n>Consider talking to him" << endl;

            count = 6;
        }
        else if (map.GetLocation(Oleg).GetName() == "Gorge" && count == 6){

            cout << "> It's wet and inappropriate here. \n> There's a large mass blocking the path� \n> Realize it isn't just a mass, it's a landwhale!" << endl;
        
            count = 7;
        }
        else if (map.GetLocation(Oleg).GetName() == "FieldB" && count == 1){

            cout << "> Wow, fucking fields for days \n> Some guy, looking pensive, wonder what he wants " << endl;
        
            count = 8;
        }
        else if (map.GetLocation(Oleg).GetName() == "Marsh" && count == 8){

            cout << "*classy gentleman appears*" << endl;
            count = 9;
        }
        else if (map.GetLocation(Oleg).GetName() == "CaveA" && count == 9){
            cout << "> Cold and dark with stalactites hanging from the ceiling \n> Feel the distant warmth of tits... should probably talk to the-- Her. I mean her." << endl;
        
            count = 10;
        }
        else if (map.GetLocation(Oleg).GetName() == "CaveB" && count == 10){
            cout << "> Shining red hair illuminates the cave \n> M- maybe I should g - go talk to her..." << endl;
        
            count = 11;
        }
        else if (map.GetLocation(Oleg).GetName() == "Goal" && count == 11){
            cout << "> Can't see anything, hear strange clicking noises \n> sounds familiar� keys on a keyboard ? \n> Not just any keyboard \n"
                "> it sounds exactly like the 20x32BAlphaMaxCustomFitErgo360Extra420 mechanical keyboard \n> like the one in... my room" << endl;
            cout << "\nShitlord: hi" << endl;
            
        
            count = 12;
        }



        cout << "---------------------------------------" << endl;
        cout << "\nPlease enter the action you would like to perform: ";
            getline(cin, action);
            action = CleanUp(action);
            cout << "---------------------------------------" << endl;

            if (action == "move") {

                Move(Oleg, map);

                cout << "Current location: " << map.GetLocation(Oleg).GetName() << endl;
            }
            else if (action == "look") {
                if (map.GetLocation(Oleg).GetNumChar() == 0 || (!(map.GetLocation(Oleg).GetChar(0).GetBeaten()) && map.GetLocation(Oleg).GetChar(0).GetEndurance() < 100)) {
                    map.GetLocation(Oleg).Look();
                    cout << Normalize(Cont(map, Oleg)) << endl;
                    toPrint = "Current Location: " + map.GetLocation(Oleg).GetName();
                    cout << Normalize(toPrint);
                }
                else if ((map.GetLocation(Oleg).GetChar(0).GetBeaten()) && map.GetLocation(Oleg).GetChar(0).GetEndurance() == 100) {
                    map.GetLocation(Oleg).Look();
                    cout << Normalize(Cont(map, Oleg)) << endl;
                    toPrint = "Current Location: " + map.GetLocation(Oleg).GetName();
                    cout << Normalize(toPrint);
                }
                else {
                    toPrint = "Senpai, don't waste time here. Continue on with your quest >_<!\n";                //Outputs to the consol when there are no living characters in the area.

                    toPrint += "\n" + map.GetLocation(Oleg).GetChar(0).GetName() + " is in the area";

                    cout << Normalize(Cont(map, Oleg)) << endl;
                    if ((map.GetLocation(Oleg).GetNumChar() == 1) && map.GetLocation(Oleg).GetChar(0).GetEndurance() == 100) {
                        cout << "\nAvailable commands:\n'move'\n'look'\n'talk'\n";
                    }
                    else {
                        cout << "\nAvailable commands:\n'move'\n'look'\n";
                        toPrint = "Current Location: " + map.GetLocation(Oleg).GetName();
                        cout << Normalize(toPrint);
                    }
                }
            }
            else if (action == "attack") {
                if (counter == 0) {

                     cout << "\nNow, one warning Senpai... from here on out, when you enter 'attack', the \ndirection of the opponent's attack will be presented on the console and you \nmust type: \n\n'right' to counterattack from the left, \n'left' to counterattack from the"
                         " right, and \n'jump' to dodge a kicking attack.\n\nYou must input the appropriate attack or dodge quickly or else your foe will \nhave succeeded in his/her attack. If your foe does succeed, you will start at\nyour original location and you may not"
                         " progress to the next stage until\nyou have beaten your opponent.\n";
                    counter += 1;
                }
        
                else {
                    if (map.GetLocation(Oleg).GetNumChar() == 0 || map.GetLocation(Oleg).GetChar(0).GetBeaten()) {
                        if (map.GetLocation(Oleg).GetChar(0).GetBeaten() && map.GetLocation(Oleg).GetChar(0).GetEndurance() == 100) {
                            cout << "< Methinks it would not be wise to attack this time... " << endl;

                        }
                        else {
                            toPrint = "There are no other enemies in your immediate vicinity. Good job, Senpai!";
                            cout << Normalize(toPrint);
                        }
                    }

                    else if (map.GetLocation(Oleg).GetChar(0).Attack(Oleg)) {
                        Oleg.SetCoord(StartCoord);
                    }
                    else {

                        toPrint = "Sugoi! You are daijoubu, and " + map.GetLocation(Oleg).GetChar(0).GetName() // name of character
                            + " will not risk another frontal assualt. ";
                        cout << Normalize(toPrint);
                        if (map.GetLocation(Oleg).GetChar(0).GetName() == "Dad") {
                            cout << "\n> Better leave before mom calls for dinner " << endl;
                            cout << "> Should be able to 'move' by typing it, then hitting an arrow key. Up is North, Left is West, etc. \n> Looks like exits are north through the front door and east through the patio " << endl;

                        }
                        else if (map.GetLocation(Oleg).GetChar(0).GetName() == "Tumblrina") {
                            cout << "> Gross. \n> Can finally head north to victory;-; " << endl;

                        }
                        else if (map.GetLocation(Oleg).GetChar(0).GetName() == "Fedora") {
                            cout << "> head east and never look back" << endl;

                        }
                        map.GetLocation(Oleg).GetChar(0).SetBeaten(true);

                    }
                }
            }
    
        else if (action == "talk") {
            map.GetLocation(Oleg).Talk();
        }
        else {
            cout << "Invalid command, Senpai. Maybe try to 'look' around." << endl;
        }
    }

    //if (map.GetMap()[1][3].GetChar(0).GetBeaten()) {
    //    toPrint = "You have successfully defeated all who have stood in your way to freedom! Now they shall all know you as 'The Legendary Black Beast of Aaaaaaargh!', a name that is quite suitable, considering your talents... "
    //        "With your newfound freedom you can make your way to the Cave of Caerbannog to live out the rest of your immortal life in the presence of your brethren. Good Luck!";
    //    cout << Normalize(toPrint) << endl;
    //    cout << endl << "***********GAME OVER***********" << endl << endl;
    //}

    return 0;
}




void Move(Player &oleg, Map &map) { // N,S,E,W -- get it to break out of the switch

    int tempArr[] = { oleg.GetCoord(0), oleg.GetCoord(1) };

    int c = 0;
    int counter = 0;
    while (counter == 0)
    {
        c = 0;

        switch ((c = _getch())) {
        case KEY_UP:
            //cout << endl << "Up" << endl;//key up
            tempArr[0] -= 1;
            if (map.isValidLocation(tempArr, oleg))
                oleg.SetCoord(tempArr);
            //cout << oleg.GetCoord(0) << oleg.GetCoord(1) << endl;
            //cout << map.GetLocation(oleg).GetName() << endl;
            //cout << map.GetLocation(oleg).GetChar(0).GetName() << endl;
            counter++;
            break;
        case KEY_DOWN:
            //cout << endl << "Down" << endl;   // key down
            tempArr[0] += 1;
            if (map.isValidLocation(tempArr, oleg))
                oleg.SetCoord(tempArr);
            //cout << oleg.GetCoord(0) << oleg.GetCoord(1) << endl;
            //cout << map.GetLocation(oleg).GetName() << endl;
            //cout << map.GetLocation(oleg).GetChar(0).GetName() << endl;
            counter++;
            break;
        case KEY_LEFT:
            //cout << endl << "Left" << endl;  // key left
            tempArr[1] -= 1;
            if (map.isValidLocation(tempArr, oleg))
                oleg.SetCoord(tempArr);
            //cout << oleg.GetCoord(0) << oleg.GetCoord(1) << endl;
            //cout << map.GetLocation(oleg).GetName() << endl;
            //cout << map.GetLocation(oleg).GetChar(0).GetName() << endl;
            counter++;
            break;
        case KEY_RIGHT:
            //cout << endl << "Right" << endl;  // key right
            tempArr[1] += 1;
            if (map.isValidLocation(tempArr, oleg))
                oleg.SetCoord(tempArr);
            //cout << oleg.GetCoord(0) << oleg.GetCoord(1) << endl;
            //cout << map.GetLocation(oleg).GetName() << endl;
            //cout << map.GetLocation(oleg).GetChar(0).GetName() << endl;
            counter++;
            break;
        default:
           // cout << endl << "null" << endl;  // not arrow
            break;
        }
    }
}

string CleanUp(string str) {
    for (int i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string Normalize(string str) {
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

string Cont(Map &map, Player &Oleg) {
    string toPrint;
    if (map.GetLocation(Oleg).GetName() == "Home") {
        toPrint += " > Should be able to 'move' north (up arrow key) to exit through the front door or east (right arrow key) to exit through the patio. ";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "FieldA") {
        toPrint += " > See a trail heading south  ";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "ClifA") {
        toPrint += " > Cliff continues to the east, better be on way";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "ClifB") {
        toPrint += " > Continue east along the cliff";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "ClifC") {
        toPrint += " >Town nearby. Only way to go is north!";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "Town") {
        toPrint += " > Nothing more to do here. Gotta head north to leave town";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "Gorge") {
        toPrint += " > Close to victory... head north!";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "FieldB") {
        toPrint += " > Head north";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "Marsh") {
        toPrint += " > Head east and never look back";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "CaveA") {
        toPrint += " > It's dark, but it seems the only way to go is east";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "CaveB") {
        toPrint += " > There's a light at the end of the cave in the east direction";
        return toPrint;
    }
    else if (map.GetLocation(Oleg).GetName() == "Goal") {
        toPrint += " > -------------------------";
        return toPrint;
    }

    



}
