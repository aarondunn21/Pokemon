#include "Player.h"
#include "time.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

Player::Player(int s) {
    srand (time(NULL));

    int ranRange = s - 2;
    //sets possible start inside borders

    xCord = rand() % ranRange + 1;
    yCord = rand() % ranRange + 1;
    //sets random coordinate

    prevMove = ' ';

}

void Player::Move(char c) {
    char moveInput = c;

    if (moveInput == 'W' || moveInput == 'w') {
        yCord--;
        prevMove = 'D';
    } else if (moveInput == 'S' || moveInput == 's') {
        yCord++;
        prevMove = 'U';
    } else if (moveInput == 'D' || moveInput == 'd') {
        xCord++;
        prevMove = 'L';
    } else if (moveInput == 'A' || moveInput == 'a') {
        xCord--;
        prevMove = 'R';
    } else {
        cout << "invalid move input";
    }
    //moves character's position in relation to input.
    //sets last position to be replaced with a '*'
}

int Player::GetX() {
    return xCord;
}

int Player::GetY() {
    return yCord;
}

char Player::GetPrev() {
    return prevMove;
}
//getters for Player character

void Player::MonsterInv(Monster &m1, Monster &m2, Monster &m3) {

    cout << endl;

    if (m1.GetHP() > 0){
        cout << "1" << ". " << m1 << endl;
    }
    if (m2.GetHP() > 0){
        cout << "2" << ". " << m2 << endl;
    }
    if (m3.GetHP() > 0){
        cout << "3" << ". " << m3 << endl;
    }
    //displays updated list of player's monsters
}
