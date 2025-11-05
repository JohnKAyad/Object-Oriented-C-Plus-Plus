#include <iostream>
#include "RPG.h"
#include "Game.h"
#include <cstdio>
using namespace std;

int main(){
   // Create a Game object
   //Create num_players as an int and set it to 10
   //Call generatePlayers(..) with num_players as the parameter
   //Call gameLoop()
    //Call printFinalResults()
    Game game;
    int num_players = 10;
    game.generatePlayers(num_players);
    game.gameLoop();
    game.printFinalResults();
   return 0;

}