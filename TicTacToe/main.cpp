//
//  main.cpp
//  TicTacToe
//
//  Created by George Peshkov on 2/28/23.
//

#include "mainClasses.h"

int main() {
    Player x('x');
    Player o('o');
    GameBoard game;
    game.printBoard();
    while(true){
        game.playerMove(x);
        game.printBoard();
        std::cout << game.evaluateGameEnd() <<"\n";
        if (game.evaluateGameEnd() == 'x') {
            std::cout << x.printUsername() << " wins the game!\n";
            return 0;
        }
        game.playerMove(o);
        game.printBoard();
        std::cout << game.evaluateGameEnd() <<"\n";
        if (game.evaluateGameEnd() == 'o'){
            std::cout << o.printUsername() << " wins the game!\n";
            return 0;
        }
    }
    return 0;
}
