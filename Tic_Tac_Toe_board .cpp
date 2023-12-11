//
// Created by lenovo on 12/10/2023.
//
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
#define _BoardGame_CLASSES_H
using namespace std;

 special_board::special_board() {
     n_rows = n_cols = 5;
     board = new char *[n_rows];
     for (int i = 0; i < n_rows; i++) {
         board[i] = new char[n_cols];
         for (int j = 0; j < n_cols; j++)
             board[i][j] = 0;
     }
 }

bool special_board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 5 || y < 0 || y > 5) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void special_board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(4) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.

bool special_board::is_winner() {

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (j<3) {
                if (board[i][j] == board[i][j + 1] == board[i][j + 2]) {
                    return true;
                }
            }
            if (i<3) {
                if (board[i][j] == board[i + 1][j] == board[i + 2][j]) {
                    return true;
                }
            }
            if (i < 3 && j < 3) {
                if (board[i][j] == board[i + 1][j + 1] == board[i + 2][j + 2]) {
                    return true;
                }
            }
            if (i < 3 && j > 1) {
                if (board[i][j] == board[i + 1][j - 1] == board[i + 2][j - 2]) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Return true if 9 moves are done and no winner
bool special_board::is_draw() {
    return (n_moves == 24 && !is_winner());
}

bool special_board::game_is_over () {
    return n_moves >= 24;
}


