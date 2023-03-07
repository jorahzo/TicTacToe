//
//  mainClasses.h
//  TicTacToe
//
//  Created by George Peshkov on 3/4/23.
//

#ifndef mainClasses_h
#define mainClasses_h

#include <iostream>
#include <string>

class Player{
public:
    Player(char playerType = 'z');
    std::string printUsername();
    char printPlayerChar();
private:
    char playerChar;
    std::string username;
};

class GameBoard{
public:
    GameBoard();
    void printBoard();
    char evaluateGameEnd();
    void playerMove(Player player);
private:
    char board[4][4];
};

#endif /* mainClasses_h */
