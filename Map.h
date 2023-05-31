#ifndef PA7_MAP_H
#define PA7_MAP_H


class Map {
public:
    explicit Map(int s);
    void PrintMap();
    void AddCharacter(int x, int y, char c);
    void AddItem();
    void AddMonster();
    void MoveCharacter(int x, int y, char p);
    void CheckInventory() const;
    bool CheckEncounter() const;
    void ResetMonster();

    bool GetMonsterEnc();
    int GetItemInventory();
    void falseMonsterEnc();
    //getters and setters

    ~Map();
    //destructor

private:
    int size;
    int itemInventory;
    char** mapArray;
    //dynamic 2d array
    bool monsterEnc;
};


#endif //PA7_MAP_H
