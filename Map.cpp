#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include "random"
#include "iostream"

using namespace std;

Map::Map(int s) {
    size = s;
    itemInventory = 0;
    monsterEnc = false;

    mapArray = new char * [size];

    mapArray[size][size];

    for (int i = 0; i < size; i++){
        mapArray[i] = new char[size];
    }

    for (int i = 0; i < size; i++){
        mapArray[0][i] = '#';
    }

    for (int i = 1; i < size - 1; i++){
        for(int j = 0; j < size -1; j++){
            mapArray[i][0] = '#';

            for (int k = 1; k < size - 1; k++){
                mapArray[i][k] = '*';
            }
            mapArray[i][size - 1] = '#';
        }
    }

    for (int i = 0; i < size; i++){
        mapArray[size - 1][i] = '#';
    }

    AddItem();

    //creates map with passed in size parameter and adds item

}

void Map::PrintMap() {
    int rowCount = 0;

    cout << endl;

    for (int i = 0; i < size; i++){
        for(int j = 0; j <= size - 1; j++){
            cout << mapArray[rowCount][j] << "  ";
        }
        cout << endl;
        rowCount++;
    }
    cout << endl;

    //prints entire map for user
}

void Map::AddCharacter(int x, int y, char c) {
    if (mapArray[y][x] == 'I'){
        AddItem();
    }
    //moves item if player is placed on top of old item

    if(c == 'P'){
        mapArray[y][x] = 'P';
    }
    //adds player to map

}

void Map::AddItem() {
    srand (time(NULL));

    int xCord, yCord;
    int ranRange = size - 2;
    //sets possible start inside borders

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> rand(1, ranRange);

    xCord = rand(rng);
    yCord = rand(rng);
    //randomly sets x and y coordinates inside of map range

    mapArray[yCord][xCord] = 'I';
    //adds item to map 2d array


}

void Map::AddMonster() {

    int xCord,yCord;
    int ranRange = size - 2;
    //sets possible start inside borders

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> rand(1, ranRange);

    xCord = rand(rng);
    yCord = rand(rng);
    //randomly sets x and y coordinates inside of map range

    while(mapArray[yCord][xCord] == 'I' ||
    mapArray[yCord][xCord] == 'P' ||
    mapArray[yCord][xCord] == 'M'){

        uniform_int_distribution<mt19937::result_type> rand(1, ranRange);

        xCord = rand(rng);
        yCord = rand(rng);
    }
    //makes sure no added element overwrites an older element


    mapArray[yCord][xCord] = 'M';
    //adds monster to 2d map array

}
void Map::MoveCharacter(int x, int y, char p) {
    if(mapArray[y][x] == 'I'){
        cout << "Item picked up!" << endl;
        itemInventory++;
    }
    //adds item to inventory

    if(mapArray[y][x] == 'M'){
        monsterEnc = true;
    }
    //sets bool if monster space is entered


    mapArray[y][x] = 'P';
    //player moved

    char prev = p;
    int oldLoc;

    if(prev == 'D'){
        oldLoc = y + 1;
        mapArray[oldLoc][x] = '*';
    }
    else if(prev == 'U'){
        oldLoc = y - 1;
        mapArray[oldLoc][x] = '*';
    }
    else if(prev == 'R'){
        oldLoc = x + 1;
        mapArray[y][oldLoc] = '*';
    }
    else if(prev == 'L'){
        oldLoc = x - 1;
        mapArray[y][oldLoc] = '*';
    }
    //covers up previous position of player

    PrintMap();


}

void Map::CheckInventory() const {
    cout << "Inventory currently contains " << itemInventory
    << " coin(s)" << endl;
}



bool Map::CheckEncounter() const {

    if(monsterEnc){
        cout << "Monster encountered! Fight Begins..." << endl;
        return true;
    }
    else{
        return false;
    }
}

void Map::ResetMonster() {
    int xCord,yCord;
    int ranRange = size - 2;
    //sets possible start inside borders

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> rand(1, ranRange);

    xCord = rand(rng);
    yCord = rand(rng);

    while(mapArray[yCord][xCord] == 'I' ||
          mapArray[yCord][xCord] == 'P' ||
          mapArray[yCord][xCord] == 'M'){

        uniform_int_distribution<mt19937::result_type> rand(1, ranRange);

        xCord = rand(rng);
        yCord = rand(rng);
        //randomly sets x and y coordinates inside of map range
    }
    //makes sure no added element overwrites an older element


    mapArray[yCord][xCord] = 'M';

    cout << "Monster has escaped!"
            " New monster found on map..." << endl;
    //gets rid of monster that player ran from, and new one is
    //generated in its place.

}

bool Map::GetMonsterEnc() {
    return monsterEnc;
}

int Map::GetItemInventory() {
    return itemInventory;
}

void Map::falseMonsterEnc() {
    monsterEnc = false;
}
//getters and setters

Map::~Map() {
    delete [] mapArray;
}
//deallocates the 2d dynamic map array




