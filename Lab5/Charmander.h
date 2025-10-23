#ifndef CHARMANDER_H
#define CHARMANDER_H
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Charmander: public Pokemon{
    public:
    // Constructor
    Charmander();
    Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s);

    // Mutators
    void speak() /* override*/;
    void printStats() /* override*/;

    private:
    vector<string> skills;
    /*name, hp, attack, defense*/
};
#endif 