#ifndef GAME_H
#define GAME_H
#include <set>
#include "RPG.h"
#include <vector>
using namespace std;

class Game{

public:
    //constructor
    Game();
    void generatePlayers(int n);
    int selectPlayer;


private:
vector<RPG*> players;
set<int> live_players;

};
#endif