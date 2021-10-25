#include "chessboardClass.h"
using namespace std;


void battle_demo() {
    ChessBoard A;
    int winner{ 0 };
    system("cls");

    while (winner == 0) {
        winner = A.player_turn(1);
        if (winner == 1) {
            break;
        }
        winner = A.player_turn(2);
    }
    A.printChessBoard(winner);
    switch (winner) {
    case 1:
        cout << "Player1 Win!!!" << endl;
        break;
    case 2:
        cout << "Player2 Win!!!" << endl;
        break;
    }
}
int main() {
    battle_demo();
    return 0;
}
