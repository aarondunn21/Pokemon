#include "BattleSequence.h"
#include "iostream"

BattleSequence::BattleSequence() {
    turnNum = 1;
    run = false;
}

bool BattleSequence::BattleSequenceLoop(Monster &eM, Monster &pM) {

    int choice = 0;

    while(pM.GetHP() > 0 && eM.GetHP() > 0){

        CurrentHealth(eM, pM);
        //displays current health of both monster

        cout << endl;
        cout << "=========" << endl;
        cout << " Turn: " << turnNum << endl;
        cout << "=========" << endl;

        Menu();
        cout << "Enter choice ";
        cin >> choice;
        //takes menu choice from user

        if (choice == 1){
            cout << "~ Waited and passed turn ~" << endl;
        }
        else if (choice == 2){
            pM.Attack(eM);
        }
        else if (choice == 3){
            SpecialAttack(eM, pM);
        }
        else if (choice == 4){
            cout << "~ Player has ran away! ~" << endl;
            run = true;
            break;

        }
        else{
            cout << "invalid choice. Turn skipped" << endl;
        }
        //four different menu choices for player to chose from

        if(eM.GetHP() <= 0){
            cout << "Our Monster has defeated the Enemy!!!" << endl << endl;
            return false;
        }
        //tells user if enemy has died

        CurrentHealth(eM, pM);
        turnNum++;
        //increase turn number after turn

        cout << "=================" << endl;
        cout << " Turn: " << turnNum << " (Enemy)" << endl;
        cout << "=================" << endl;

        eM.Attack(pM);
        //enemy takes their turn
        turnNum++;

        if(pM.GetHP() <= 0){
            cout << "The Enemy has won this battle..." << endl << endl;
            return true;
        }
        //tells user if their monster has died

    }
    return true;
}

void BattleSequence::CurrentHealth(Monster &eM, Monster &pM) {
    cout << endl;
    cout << "(Current Health) " << eM << " | (PLAYER) "
    << pM << endl << endl;
}

void BattleSequence::SpecialAttack(Monster &eM, Monster &pM) {
    if (pM.GetType() == 'F' && eM.GetType() == 'G'){
        pM.SpecialAttack(eM);
    }
    else if (pM.GetType() == 'G' && eM.GetType() == 'W'){
        pM.SpecialAttack(eM);
    }
    else if (pM.GetType() == 'W' && eM.GetType() == 'F'){
        pM.SpecialAttack(eM);
    }
    else{
        cout << "Special attack not Applicable. Turn skipped!" << endl;
    }
    //finds if special attack is applicable and applys it
}

void BattleSequence::Menu() {
    cout << endl;
    cout << "==========Menu==========" << endl;
    cout << " (1) Wait (pass turn)" << endl;
    cout << " (2) Physical Attack" << endl;
    cout << " (3) Special Attack" << endl;
    cout << " (4) Run" << endl;
    cout << "========================" << endl << endl;

}

bool BattleSequence::GetRun() {
    return run;
}

