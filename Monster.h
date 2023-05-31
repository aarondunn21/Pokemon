#ifndef PA72_MONSTER_H
#define PA72_MONSTER_H

#include "string"
#include "iostream"

using namespace std;


class Monster {
public:
    string GetName() const{
        return name;
    };
    int GetHP() const{
        return healthPoints;
    };
    int GetAttackDMG() const{
        return attackDamage;
    };
    char GetType() const{
        return monsterType;
    };
    void SetHP(int a){
        healthPoints = a;
    }
    //getters and setters for member data

    void Attack(Monster& m){
        m.healthPoints = m.healthPoints - attackDamage;
        cout << "~ " << *this << " has attacked " <<
        "for " << attackDamage << " damage!" << " ~" << endl;
    }
    void SpecialAttack(Monster& m){
        m.healthPoints = m.healthPoints - (attackDamage * 2);
        cout << "~ " << *this << " has attacked " <<
             "for " << (attackDamage * 2) << " special damage! ~" << endl;
    }
    //computes attack results and informs user


    friend ostream &operator<<(ostream &output, const Monster& m){
        string type = "NULL";

        if(m.monsterType == 'F'){
            type = "Fire type ";
        }
        else if(m.monsterType == 'W'){
            type = "Water type ";
        }
        else if(m.monsterType == 'G'){
            type = "Grass type ";
        }

        cout << m.name << " (" << type << m.healthPoints
        << "HP)";

        return output;
    }
    //output overload for monster objects


protected:
    string name;
    int healthPoints;
    int attackDamage;
    char monsterType;

};


#endif //PA72_MONSTER_H
