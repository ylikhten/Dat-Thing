#include"Player.h"

// Default Constructor
Player::Player() {
    health = 10;
    coordinates[0] = 3;
    coordinates[1] = 0;
}

// Non-default Constructor
Player::Player(int health, int coordinates) {

}

//Mutator and Accessor functions
void Player::SetCoord(int Coords[2]) {
    coordinates[0] = Coords[0];
    coordinates[1] = Coords[1];
}

int Player::GetCoord(int index) const {
    if (index < 0 || index > 1) {
        cout << "GetCoord index is out of range D:" << endl;
        exit(1);
    }
    return coordinates[index];
}

int Player::GetHealth() const {
    return health;
}
void Player::SetHealth(int health) {
    if (health > 0 && health < MAX_HEALTH)
        this->health = health;
    if (health <= 0) {
        cout << "\n\nYou have been beaten into a bloody pulp and will never recover your gains... ;-;" << endl << endl << "***********GAME OVER***********" << endl;
        exit(1);
    }
}