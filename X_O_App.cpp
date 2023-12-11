// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int x;
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child

cout<<"Press 1 to play 3x3 X-O\npress 2 to play 5x5 X-O\n ";
cin>>choice;
    if (choice==1){
        players[1] = new RandomPlayer ('o', 3);
    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();}
    else {
        players[1] = new special_player ('o', 5);
     GameManager tic_tac_toe (new special_board(), players);
     tic_tac_toe.run_tic();
    }


    system ("pause");
}
