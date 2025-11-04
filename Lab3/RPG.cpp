#include <iostream>
#include <string>
#include <random>
#include "RPG.h"
using namespace std;

//Default constructor
RPG::RPG(){
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50.0;
    level = 1;
}

RPG::RPG(string name, int hits_taken, float luck, float exp, int level){
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

//mutators
 bool RPG::isAlive() const{
    if(hits_taken < MAX_HITS_TAKEN){
        cout << name << " 1\n";
        return true;
    }
    else{
        cout << name << " 0\n";
        return false;
    }
}

void RPG::setHitsTaken(int new_hits){
    hits_taken = new_hits;
}

void RPG::setName(string name){
    this->name = name;
}

void RPG::updateExpLevel(){
    exp +- 50;
    if(exp >= 100){
        level += 1;
        exp = 0;
        luck += .1;
    }
}

void RPG::attack (RPG * opponent){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);
    bool hit = random_num > HIT_FACTOR * (* opponent).getLuck();

    if(hit){ // (hit == true)  
        opponent -> setHitsTaken(opponent -> getHitsTaken() + 1);

    }
}


//accessors
string RPG::getName() const{
    return name;
}

int RPG::getHitsTaken() const{
    return hits_taken;
}
float RPG::getLuck() const{
    return luck;
}
float RPG::getExp() const{
    return exp;
}
int RPG::getLevel() const{
    return level;
}

