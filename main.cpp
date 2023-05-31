/* ==========================================================================
    AUTHOR: Aaron Dunn

SUMMARY
This program builds a randomized and playable Pokemon game that allows you to
traverse a custom sized map to pick up items and battle randomized enemy monsters
with the monsters in your inventory.
*/

/* ========================================================================== */

#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include "Monster.cpp"
#include "BattleSequence.h"
#include "random"

using namespace std;

int main() {

    random_device dev;
    mt19937 rng(dev());
    //sets up random library for later use

    cout << "Enter size of map (Greater than 4): " << endl;
    int size;
    char moveInput = ' ';
    cin >> size;
    //uses user's requested size

    Map m1(size);
    Player p1(size);
    //builds map and adds player

    BigMonster b1('W');
    BigMonster b2('F');
    SmallMonster s1('G');
    //player's monster inventory


    m1.AddCharacter(p1.GetX(), p1.GetY(), 'P');

    int numRangeMonsters = 4;
    uniform_int_distribution<mt19937::result_type> randMon(2, numRangeMonsters);
    int numMonsterChoice = randMon(rng);
    for (int i = 0; i < numMonsterChoice; i++){
        m1.AddMonster();
    }
    //create random number of monsters

    m1.PrintMap();


    int playerMonsterChoice;
    //holds player's choice of monster for battle

    int numWins = 0;
    //number of battle wins to determine overall win
    int numLosses = 0;
    //number of battle losses to determine overall loss



    while(moveInput != 'q') {
        cout << "enter move choice, q to quit: ";
        cin >> moveInput;
        p1.Move(moveInput);
        m1.MoveCharacter(p1.GetX(), p1.GetY(), p1.GetPrev());
        m1.CheckEncounter();

        if(m1.GetMonsterEnc()){
            int sizeRangeSize = 2;
            int typeRangeSize = 3;
            //sets possible ranges inside borders

            uniform_int_distribution<mt19937::result_type> rand(1, sizeRangeSize);
            int sizeChoice = rand(rng);
            //randomly gets a number for size of monster

            uniform_int_distribution<mt19937::result_type> rand2(1, typeRangeSize);
            int typeChoice = rand2(rng);
            //randomly gets a number for type of monster

            char typeChar;

            if (typeChoice == 1){
                typeChar = 'F';
            }
            else if (typeChoice == 2){
                typeChar = 'W';
            }
            else if (typeChoice == 3){
                typeChar = 'G';
            }
            else{
                cout << "error with type" << endl;
            }
            //sets type parameter with randomized number

            BattleSequence bs1;
            //create battle sequence default object
            bool playerMonsDeath = false;
            //if player's monster dies, set to true

            if (sizeChoice == 1){
                BigMonster e1(typeChar);
                cout << "Enemy: " << e1 << endl;
                cout << "Which of your monsters do you want to use? " << endl;
                p1.MonsterInv(b1, b2, s1);

                cin >> playerMonsterChoice;

                if (playerMonsterChoice == 1){
                    playerMonsDeath = bs1.BattleSequenceLoop(e1, b1);
                }
                else if (playerMonsterChoice == 2){
                    playerMonsDeath = bs1.BattleSequenceLoop(e1, b2);
                }
                else if (playerMonsterChoice == 3){
                    playerMonsDeath = bs1.BattleSequenceLoop(e1, s1);
                }
                else{
                    cout << "Invalid monster choice" << endl;
                }
                //creates a random big enemy monster
                //allows user to choose monster to attack enemy


            }
            else if (sizeChoice == 2){
                SmallMonster e1(typeChar);
                cout << "Enemy: " << e1 << endl;
                cout << "Which of your monsters do you want to use?" << endl;
                p1.MonsterInv(b1, b2, s1);

                cin >> playerMonsterChoice;

                if (playerMonsterChoice == 1){
                    playerMonsDeath = bs1.BattleSequenceLoop(e1, b1);
                }
                else if (playerMonsterChoice == 2){
                    playerMonsDeath = bs1.BattleSequenceLoop(e1, b2);
                }
                else if (playerMonsterChoice == 3){
                    playerMonsDeath = bs1.BattleSequenceLoop(e1, s1);
                }
                else{
                    cout << "Invalid monster choice" << endl;
                }
                //creates a random small enemy monster
                //allows user to choose monster to attack enemy

            }
            if(bs1.GetRun()){
                m1.ResetMonster();
                //if player decides to run, monster is replaced
            }
            else if(playerMonsDeath){
                m1.ResetMonster();
                numLosses++;
                //if player's monster dies, enemy is replaced
            }
            else{
                numWins++;
                //if enemy is eliminated, win counter goes up
            }

            if (numWins == numMonsterChoice && m1.GetItemInventory() > 0){
                cout << endl << endl;
                cout << "Congratulations! You have defeated all enemy"
                        " monsters and collected all items. "
                        "You have won the game!" << endl;
                m1.CheckInventory();
                break;
            }
            //tells user if they have won the game

            if (numLosses == 3){
                cout << endl << endl;
                cout << "Sorry, all of your monsters died. "
                        "You have lost the game." << endl;
                m1.CheckInventory();
                break;

            }
            //if all friendly monsters die, player loses the game

            m1.falseMonsterEnc();
            m1.PrintMap();
            //reset monster encounter bool and prints map
        }

        m1.CheckInventory();
        //tells user inventory after every turn
    }

    cout << "Thank you for playing!" << endl;




    return 0;
}
