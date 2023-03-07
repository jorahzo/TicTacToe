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
    while(true){
        if (player.printPlayerChar() == 'x'){
            std::cout << "Please make a move " << player.printUsername() << "\n";
            int column;
            std::cout << "What column?\n";
            std::cin >> column;
            int row;
            std::cout << "What row?\n";
            std::cin >> row;
            if(board[row-1][column-1] == 'o'){
                std::cout << "\nInvalid move. Other player has made a move here already. Try again\n\n";
                continue;
            }
            else if (board[row-1][column-1] == 'x'){
                std::cout << "\nYou have already made a move here. Pick a new space\n\n";
                continue;
            }
            else if ((row > 4) || (row < 1) || (column > 4) || (column < 1)){
                std::cout << "\nRow and/or column selection is not valid. Please try again\n\n";
                continue;
            }
            else{
                board[row-1][column-1] = 'x';
                break;
            }
        }
        else if (player.printPlayerChar() == 'o'){
            std::cout << "Please make a move " << player.printUsername() << "\n";
            int column;
            std::cout << "What column?\n";
            std::cin >> column;
            int row;
            std::cout << "What row?\n";
            std::cin >> row;
            if(board[row-1][column-1] == 'x'){
                std::cout << "\nInvalid move. Other player has made a move here already. Try again\n\n";
                continue;;
            }
            else if (board[row-1][column-1] == 'o'){
                std::cout << "\nYou have already made a move here. Pick a new space\n";
                continue;
            }
            else if ((row > 4) || (row < 1) || (column > 4) || (column < 1)){
                std::cout << "\nRow and/or column selection is not valid. Please try again\n\n";
                continue;
            }
            else{
                board[row-1][column-1] = 'o';
                break;
            }
        }
        break;
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
    // Check if user X has 4 x's in one row
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
    // Check if user X has 4 x's in one column
    for(int i = 0; i < 4; i++){
        int count = 0;
        for(int j = 0; j < 4; j++){
            if(board[j][i] == 'x'){
                count++;
                if (count == 4){
                    return 'x';
                }
            }
        }
    }
    // Check if user X has 4 x's in a diagonal
    if((board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x' && board[3][3] == 'x')||(board[3][0] == 'x' && board[2][1] == 'x' && board[1][2] == 'x' && board[0][3] == 'x')){
        return 'x';
    }
    // Check if user O has 4 O's in one row
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
    // Check if user O has 4 O's in one column
    for(int i = 0; i < 4; i++){
        int count = 0;
        for(int j = 0; j < 4; j++){
            if (board[j][i] == 'o'){
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
    // Check if user O has 4 O's in a diagonal.
    if((board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o' && board[3][3] == 'o')||(board[3][0] == 'o' && board[2][1] == 'o' && board[1][2] == 'o' && board[0][3] == 'o')){
        return 'o';
    }
    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if ((board[i][j] == 'x') || board[i][j] == 'o'){
                count++;
            }
        }
        if (count == 16){
            return 'y';
        }
    }
    return 'z';
}
    Player::Player(char playerType){
        playerChar = playerType;
        std::cout << "Please enter username for player " << playerChar << "\n";
        std::string nameInput;
        std::getline(std::cin, nameInput);
        this->username = nameInput;
    }

    char Player::printPlayerChar(){
        return this->playerChar;
    }

    std::string Player::printUsername(){
        return this->username;
    }
