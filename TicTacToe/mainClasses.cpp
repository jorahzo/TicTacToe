    //
    //  mainClasses.cpp
    //  TicTacToe
    //
    //  Created by George Peshkov on 3/4/23.
    //

    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include "mainClasses.h"


    GameBoard::GameBoard(){
        for(int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                board[i][j] = '*';
            }
        }
    }

    void GameBoard::playerMove(Player player){
        if (player.printPlayerChar() == 'x'){
            std::cout << "Please make a move " << player.printUsername() << "\n";
            int row;
            std::cout << "What row?\n";
            std::cin >> row;
            int column;
            std::cout << "What column?\n";
            std::cin >> column;
            board[row][column] = 'x';
        }
        else if (player.printPlayerChar() == 'o'){
            std::cout << "Please make a move " << player.printUsername() << "\n";
            int row;
            std::cout << "What row?\n";
            std::cin >> row;
            int column;
            std::cout << "What column?\n";
            std::cin >> column;
            board[row][column] = 'o';
        }
        else{
            std::cout << "I don't think you're real? Aborting game.";
            abort();
        }
        
    }

    void GameBoard::printBoard(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

char GameBoard::evaluateGameEnd(){
    for(int i = 0; i < 4; i++){
        int count = 0;
        for(int j = 0; j < 4; j++){
            if (board[i][j] == 'x'){
                count++;
                if (count == 4){
                    return 'x';
                }
            }
            else{
                count = 0;
            }
        }
    }
    for(int i = 0; i < 4; i++){
        int count = 0;
        for(int j = 0; j < 4; j++){
            if (board[i][j] == 'o'){
                count++;
                if (count == 4){
                    return 'o';
                }
            }
            else{
                count = 0;
            }
        }
    }
    return 'z';
}
    Player::Player(char playerType){
        playerChar = playerType;
        std::cout << "Please enter username for player " << playerChar << "\n";
        std::string nameInput;
        std::cin >> nameInput;
        this->username = nameInput;
    }

    char Player::printPlayerChar(){
        return this->playerChar;
    }

    std::string Player::printUsername(){
        return this->username;
    }
