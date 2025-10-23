#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
using namespace std;

class Pokemon {
    public:
    // Constructor
    Pokemon();
    Pokemon(string name, int hp, int att, int def, vector<string> type);
    
    //mutators
    virtual void speak();
    virtual void printStats();

    //accessors
    protected:
    string name;
    int hp;
    int attack;
    int defense;
    vector<string> type;
};
#endif 