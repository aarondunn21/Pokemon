#include "Monster.h"




class BigMonster : public Monster {
public:
    BigMonster(char t){
        name = "Big Monster";
        healthPoints = 120;
        attackDamage = 20;
        monsterType = t;
    }
    //constructor for Big monster
};

class SmallMonster : public Monster {
public:
    SmallMonster(char t){
        name = "Small Monster";
        healthPoints = 80;
        attackDamage = 5;
        monsterType = t;
    }
    //constructor for Small monster
};

