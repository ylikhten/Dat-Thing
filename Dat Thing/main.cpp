#include <iostream>
#include <conio.h>
#include "Map.h"
using namespace std;

const int MAX_CHR = Location::MAX_CHR;

void Move( Player &oleg, Map &map);
string CleanUp(string str);
string Normalize(string str);

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


int main() {

    int StartCoord[2] = { 3, 0 };
    string action;
    char pDir;
    string toPrint;
    int counter = 0;

    Map map("mapu.map");
    Player Oleg;


    
    Character Dad; //1
    Character Troll(100, 10, true, "Troll"); //2
    Character Nazi(1, 1, false, "Grammar Nazi"); //3
    Character Atheist(1, 1, false, "Middle School Atheist");   //4
    Character Bro(1, 1, false, "Fit Bro");    //5
    Character Cums(1, 1, false, "Big Cums"); //6
    Character Stan(1, 1, false, "Stan");   //7
    Character Oppai(100, 10, true, "Oppai Chan");    //8
    Character Charf(100, 10, true, "An Hero"); //9 
    Character Shinji(100, 10, true, "Shinji");   //10
    Character Fuccboi(100, 10, true, "fuccboi");    //11
    Character Tumbl(1, 1, false, "Tumblrina"); //12
    Character Tsun(1, 1, false, "Tsundere Masterrace");   //13
    Character Grill(100, 10, true, "Gamer Grill");    //14
    Character Vegeta(1, 1, false, "Vegeta"); //15-- if endurance == 100 "eeh... you dont to fight me..."
    Character Shitlord(10, 10, false, "Shitlord");   //16


    map.GetMap()[3][0].AddChar(Dad);  //1
    map.GetMap()[3][1].AddChar(Troll);   //2
    map.GetMap()[2][0].AddChar(Nazi);   //3
    map.GetMap()[2][1].AddChar(Atheist);  //4
    map.GetMap()[4][1].AddChar(Bro);    //5
    map.GetMap()[1][0].AddChar(Cums);   //6
    map.GetMap()[4][2].AddChar(Stan);  //7
    map.GetMap()[1][1].AddChar(Oppai);    //8
    map.GetMap()[4][3].AddChar(Charf);   //9
    map.GetMap()[1][2].AddChar(Shinji);  //10
    map.GetMap()[3][3].AddChar(Fuccboi);    //11
    map.GetMap()[2][3].AddChar(Tumbl);   //12
    map.GetMap()[1][3].AddChar(Tsun);  //13
    map.GetMap()[1][4].AddChar(Grill);    //14
    map.GetMap()[0][3].AddChar(Vegeta);   //15
    map.GetMap()[0][4].AddChar(Shitlord);  //16


    //Gameplay stuff
    //cout << "***********PLIGHT OF THE VAMPIRE RABBIT***********" << endl;
    //toPrint = "It's a dark, stormy night and you (Bunnicula) have just woken up on the first floor of Brown Building in what appears to be a computer lab. "
    //    "Disoriented and confused, an urgent thought comes into your mind I have to get out of here! "
    //    "And so, dear, fluffy adventurer, your journey begins. You may want to 'look' around to see what is immediately surrounding you. Base your actions on what you see. (Enter 'look,' sans apostrophes.)";
    //cout << Normalize(toPrint);


    while (!map.GetMap()[0][4].GetChar(0).GetBeaten()) {

            cout << "\nPlease enter the action you would like to perform: ";
            getline(cin, action);
            action = CleanUp(action);

            if (action == "move") {
                //cout << "Direction: ";
                //cin >> pDir;
                //getline(cin, toPrint);
                ////cin.ignore();
                //Move(pDir, James, BrownMap);

                Move(Oleg, map);
                cout << "Current location: " << map.GetLocation(Oleg).GetName() << endl;
            }
            else if (action == "look") {
                if (map.GetLocation(Oleg).GetNumChar() == 0 || !(map.GetLocation(Oleg).GetChar(0).GetBeaten())) {
                    map.GetLocation(Oleg).Look();
                    toPrint = "Current Location: " + map.GetLocation(Oleg).GetName();
                    cout << Normalize(toPrint);
                }
                else {
                    toPrint = "There is no one to feed on in this area. Better move along to the next area.";                //Outputs to the consol when there are no living characters in the area.
                    if (map.GetLocation(Oleg).GetName() == "Lab") {
                        toPrint += " There is an exit to the north. ";
                    }
                    else if (map.GetLocation(Oleg).GetName() == "Starbucks") {
                        toPrint += " Inside the cubic parameter of the coffee dispensary, you see a woman working at this establishment. You also note a hallway to the east. ";
                    }
                    else if (map.GetLocation(Oleg).GetName() == "HallwayB") {
                        toPrint += " The final step in your quest for freedom lies to the east.";
                    }
                    toPrint += map.GetLocation(Oleg).GetChar(0).GetName() + " is in the room.";
                    cout << Normalize(toPrint) << endl;
                    if ((map.GetLocation(Oleg).GetNumChar() == 2)) {
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
                     cout << "\nNow, one warning... from here on out, when you enter 'attack', the direction\nof the opponent's attack will be presented on the consol and you must type: \n\n'right' to dodge an oncoming attack from the left, \n'left' to dodge an attack coming from the"
                         " right, and \n'jump' to dodge a kicking attack.\n\nYou must input the appropriate dodge quickly or else your foe will have\nsucceeded in his/her attack. If your foe does succeed, you will start at\nyour original location and you may not"
                         " progress to the next stage until\nyou have beaten your opponent.\n";
                    counter += 1;
                }
        
                else {
                    if (map.GetLocation(Oleg).GetNumChar() == 0 || map.GetLocation(Oleg).GetChar(0).GetBeaten()) {
                        toPrint = "There are no other living beings in your immediate vicinity.";
                        cout << Normalize(toPrint);
                    }
                    else if (map.GetLocation(Oleg).GetChar(0).Attack(Oleg)) {
                        Oleg.SetCoord(StartCoord);
                    }
                    else {

                        toPrint = "Congratulations! You are dynamite, and " + map.GetLocation(Oleg).GetChar(0).GetName() // name of character
                            + " will not risk another frontal assualt. ";
                        cout << Normalize(toPrint);
                        map.GetLocation(Oleg).GetChar(0).SetBeaten(true);

                        //if (map.GetLocation(Oleg).GetName() == "Lab") {
                        //    cout << endl << endl;
                        //    toPrint = "Now that you have regained some strength, you may want to 'move'. Figure out in which cardinal direction ('n', 's', 'e', 'w') you would like to go, then type 'move'";
                        //    cout << Normalize(toPrint) << endl;
                        //}
                    }
                }
            }
    
        else if (action == "talk" && map.GetLocation(Oleg).GetName() == "Starbucks") {
            map.GetLocation(Oleg).Talk();
        }
        else {
            cout << "That is not a valid command. Maybe try to 'look' around." << endl;
        }
    }

    //if (BrownMap.GetMap()[0][2].GetChar(0).GetBeaten()) {
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
            cout << endl << "Up" << endl;//key up
            tempArr[0] -= 1;
            if (map.isValidLocation(tempArr, oleg))
                oleg.SetCoord(tempArr);
            cout << oleg.GetCoord(0) << oleg.GetCoord(1) << endl;
            cout << map.GetLocation(oleg).GetName() << endl;
            cout << map.GetLocation(oleg).GetChar(0).GetName() << endl;
            counter++;
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            tempArr[0] += 1;
            if (map.isValidLocation(tempArr, oleg))
                oleg.SetCoord(tempArr);
            cout << oleg.GetCoord(0) << oleg.GetCoord(1) << endl;
            cout << map.GetLocation(oleg).GetName() << endl;
            cout << map.GetLocation(oleg).GetChar(0).GetName() << endl;
            counter++;
            break;
        case KEY_LEFT:
            cout << endl << "Left" << endl;  // key left
            tempArr[1] -= 1;
            if (map.isValidLocation(tempArr, oleg))
                oleg.SetCoord(tempArr);
            cout << oleg.GetCoord(0) << oleg.GetCoord(1) << endl;
            cout << map.GetLocation(oleg).GetName() << endl;
            cout << map.GetLocation(oleg).GetChar(0).GetName() << endl;
            counter++;
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;  // key right
            tempArr[1] += 1;
            if (map.isValidLocation(tempArr, oleg))
                oleg.SetCoord(tempArr);
            cout << oleg.GetCoord(0) << oleg.GetCoord(1) << endl;
            cout << map.GetLocation(oleg).GetName() << endl;
            cout << map.GetLocation(oleg).GetChar(0).GetName() << endl;
            counter++;
            break;
        default:
           // cout << endl << "null" << endl;  // not arrow
            break;
        }


        //int tempArr[] = { oleg.GetCoord(0), oleg.GetCoord(1) };

        //switch (direction) {
        //case 'N':
        //case 'n':
        //    tempArr[0] -= 1;
        //    if (map.isValidLocation(tempArr, oleg))
        //        oleg.SetCoord(tempArr);
        //    break;
        //case 'S':
        //case 's':
        //    tempArr[0] += 1;
        //    if (map.isValidLocation(tempArr, oleg))
        //        oleg.SetCoord(tempArr);
        //    break;
        //case 'E':
        //case 'e':
        //    tempArr[1] += 1;
        //    if (map.isValidLocation(tempArr, oleg))
        //        oleg.SetCoord(tempArr);
        //    break;
        //case 'W':
        //case 'w':
        //    tempArr[1] -= 1;
        //    if (map.isValidLocation(tempArr, oleg))
        //        oleg.SetCoord(tempArr);
        //    break;
        //case 'X':
        //    cout << "The world explodes. Goodbye." << endl;
        //    exit(1);
        //default:
        //    cout << "Invalid command. Try N, S, W, or E." << endl;
        //    break;
        //}

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