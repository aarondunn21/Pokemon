#ifndef PA72_BATTLESEQUENCE_H
#define PA72_BATTLESEQUENCE_H

#include "Monster.h"

class BattleSequence {
public:
    BattleSequence();
    bool BattleSequenceLoop(Monster& eM, Monster& pM);
    //loop that drives battle

    static void CurrentHealth(Monster &eM, Monster &pM);
    //prints out current health of both monster

    static void SpecialAttack(Monster &eM, Monster &pM);
    //special attack choice from player

    void Menu();
    //prints menu choices

    bool GetRun();
    //returns if player has chosen to run


private:
    int turnNum;
    bool run;
};


#endif //PA72_BATTLESEQUENCE_H
