#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <algorithm>
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
    return hits_taken < MAX_HITS_TAKEN;
}

void RPG::setHitsTaken(int new_hits){
    hits_taken = new_hits;
}

void RPG::setName(string name){
    this->name = name;
}

void RPG::updateExpLevel(){
    exp += 50;
    if(exp >= 100){
        level += 1;
        exp = 0;
        luck += .1;
    }
}

void RPG::attack (RPG * opponent){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0.0f, 1.0f);

    float random_num = dis(gen);
    // Clamp luck to avoid invincible players and ensure progress
    float effLuck = opponent->getLuck();
    if (effLuck < 0.0f) effLuck = 0.0f;
    if (effLuck > 0.9f) effLuck = 0.9f; // max 90% dodge chance
    bool hit = random_num > effLuck;

    if (hit) {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}

/**
 * @brief prints in the format:
 * "Name: NPC__X        Hits Taken: X       Luck: 0.X00000      Exp: X0.00000       Level: X    Status: Alive or Dead"
 * 
 * @return string 
 */

void RPG::printStats() const{
    cout << "Name: " << name
         << "       Hits Taken: " << hits_taken
         << "       Luck: " << fixed << setprecision(5) << luck
         << "      Exp: " << fixed << setprecision(5) << exp
         << "       Level: " << level
         << "    Status: " << (isAlive() ? "Alive" : "Dead")
         << "\n";
}

//Destroy the RPG::RPG object
RPG::~RPG(){
    //cout << "RPG Object Destroyed\n";
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

