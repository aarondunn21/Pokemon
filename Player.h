#ifndef PA7_PLAYER_H
#define PA7_PLAYER_H

#include "Monster.h"


class Player {
public:
    explicit Player(int s);
    void Move(char c);
    //move player with inputted WSAD

    int GetX();
    int GetY();
    char GetPrev();
    //getters for player position

    static void MonsterInv(Monster& m1, Monster& m2, Monster& m3);
    //holds current monsters and their health

private:
    int xCord, yCord;
    char prevMove;

};


#endif //PA7_PLAYER_H
