//
//  main.cpp
//  TicTacToe
//
//  Created by George Peshkov on 2/28/23.
//

#include "mainClasses.h"

int main() {
    Player x('x');
    Player y('y');
    GameBoard game;
    std::cout << x.printUsername() << "\n";
    std::cout << y.printUsername() << "\n";
    game.printBoard();
    return 0;
}
