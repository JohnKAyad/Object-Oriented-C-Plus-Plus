//Game.cpp
#include "Game.h"
#include "RPG.h"
#include <random>
#include <iostream>
using namespace std;
Game::Game(){
}

/**
 * @brief creates up to n RPG pointers and updates names
 * with ordering. Populates live_players from 0 to n-1 as
 * all players are alive initially.
 * 
 * @param n: numer of players
 */
 
 void Game::generatePlayers(int n){
    for (int i = 0; i < n; i++){
        players.push_back(new RPG());

        //rename players
        string new_name = "NPC__" + to_string(i);
        players[i]->setName(new_name);
        live_players.insert(i);
    }
 }

 /**
  * @brief Randomly selects a player (via index) from the 
  * set of alive players, live_players
  * 
  * @return int: index for vector, players
  * 
  * 
  */

  int Game::selectPlayer(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() - 1);

    int random_index = dist(gen); //pick random index
    
    set<int>::iterator it = live_players.begin();
    advance(it, random_index);

    int selectedIndex = *it;
    return selectedIndex;
  }

  /**
   * @brief Resets winner's hits_taken to 0.
   * Removes the loser from the live_players.
   * Calls updateExpLevel() for the winnder
   * prints the structure "NPC_X won against NPC_Y"
   * 
   * @param winner: pointer to RPG winner
   * @param loser: pointer to RPG loser
   * @param loserIndex: int index of loser, so that it can be removed from
   * live_players
   * 
   */

   void Game::endRound(RPG *winner, RPG *loser, int loserIndex){
    winner -> setHitsTaken(0);
    live_players.erase(loserIndex);
    winner -> updateExpLevel();

    cout << winner -> getName() << " won against " << loser -> getName() << endl;
   }

   /**
    * @brief calls selectPlayer() twice to get 2 players at random. IF the players are redundant
    * make a recursive clal to battleRound() and return.
    * Run a round of hits across player1 and player 2 until only 1 is alive
    * Call endRound() to highlight who won and update stats
    * 
    */

    void Game::battleRound(){
        int player1Index = selectPlayer();
        int player2Index = selectPlayer();

        if(player1Index == player2Index){
            battleRound();
            return;
        }

        RPG* player1 = players[player1Index];
        RPG* player2 = players[player2Index];

        while(player1 -> isAlive() && player2 -> isAlive()){
            player1 -> attack(player2);
            if(player2 -> isAlive()){
                player2 -> attack(player1);
            }
        }

        if(player1 -> isAlive()){
            endRound(player1, player2, player2Index);
        }
        else{
            endRound(player2, player1, player1Index);
        }
    }

    /**
     * @brief Runs battleRound() until there is only 1 player alive
     * Remember that endRound() shrinks the size of live_players
     * 
     */

     void Game::gameLoop(){
        while(live_players.size() > 1){
            battleRound();
        }
     }

     /**
      * @brief calls printStats on all the platers
      * 
      */

      void Game::printFinalResults(){
        for(auto &player : players){
            player -> printStats();
        }
      }

      /**
       * @brief Destroy the Game::Game object
       * 
       */

       Game::~Game(){

       }

       