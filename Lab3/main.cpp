#include <iostream>
#include "RPG.h"
#include <cstdio>
using namespace std;

int main(){
    RPG p1 = RPG("Wiz", 0 , 0.2, 60, 1);
    RPG p2 = RPG();

    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p1.getHitsTaken(), p1.getLuck(), p1.getExp(), p1.getLevel());

    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p2.getHitsTaken(), p2.getLuck(), p2.getExp(), p2.getLevel());

    p2.setHitsTaken(3);

    cout << "\n" << p2.getName() << " hits taken ";
    printf("%i\n", p2.getHitsTaken());

    cout << "\n" << p1.getName() << " hits taken ";
    printf("%i\n", p1.getHitsTaken());

    cout << "0 is dead, 1 is alive\n";
    p1.isAlive();
    p2.isAlive();

    return 0;

}