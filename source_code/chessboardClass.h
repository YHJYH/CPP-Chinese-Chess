#pragma once
#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "ChessClass.h"
//#include "c_boardClass.h"
using namespace std;

struct position {
    int y;
    int x;
};

int get_x(int num) {
    return num % 9;
}
int get_y(int num) {
    return num / 10;
}
int get_num(int y, int x) {
    return y * 9 + x;
}

class ChessBoard {
    friend int get_x(int num);
    friend int get_y(int num);
    friend int get_num(int y, int x);
private:
    Chess** Board = new Chess * [90];
public:
    c_board& cb = *new c_board();
public:
    ChessBoard() {
        Init();
    }
    ~ChessBoard() {}

    void Init();
    void ChessCreated(int y, int x, Chess* new_chess);

    char MoveChess(int initial_y, int initial_x, int final_y, int final_x);

    bool board_mdecision(int initial_y, int initial_x, int final_y, int final_x);

    //bool boardTraversal(int initial_y, int initial_x);

    int player_turn(int turn_team);

    void cb_choices_clear() {
        cb.choices_clean();
    }

    void printChessBoard(int turn_team);

    char get_chess_mark(int y, int x) {
        //return Board[get_num(y,x)]->get_mark();
        return cb.get_cmark(y, x);
    }

    Chess& get_Chess(int y, int x) {
        return *Board[get_num(y, x)];
    }
};

void::ChessBoard::Init() {
    for (int i{};i < 90; i++) {
        Board[i] = new Empty(get_y(i), get_x(i), &cb);
    }
    ChessCreated(0, 0, new Chariot1(0, 0, &cb));
    ChessCreated(0, 1, new Horse1(1, 0, &cb));
    ChessCreated(0, 2, new Elephant1(2, 0, &cb));
    ChessCreated(0, 3, new Advisor1(3, 0, &cb));
    ChessCreated(0, 4, new General1(4, 0, &cb));
    ChessCreated(0, 5, new Advisor1(5, 0, &cb));
    ChessCreated(0, 6, new Elephant1(6, 0, &cb));
    ChessCreated(0, 7, new Horse1(7, 0, &cb));
    ChessCreated(0, 8, new Chariot1(8, 0, &cb));
    ChessCreated(2, 1, new Cannon1(1, 2, &cb));
    ChessCreated(2, 7, new Cannon1(7, 2, &cb));
    ChessCreated(3, 0, new Soldier1(0, 3, &cb));
    ChessCreated(3, 2, new Soldier1(2, 3, &cb));
    ChessCreated(3, 4, new Soldier1(4, 3, &cb));
    ChessCreated(3, 6, new Soldier1(6, 3, &cb));
    ChessCreated(3, 8, new Soldier1(8, 3, &cb));

    ChessCreated(9, 0, new Chariot2(0, 9, &cb));
    ChessCreated(9, 1, new Horse2(1, 9, &cb));
    ChessCreated(9, 2, new Elephant2(2, 9, &cb));
    ChessCreated(9, 3, new Advisor2(3, 9, &cb));
    ChessCreated(9, 4, new General2(4, 9, &cb));
    ChessCreated(9, 5, new Advisor2(5, 9, &cb));
    ChessCreated(9, 6, new Elephant2(6, 9, &cb));
    ChessCreated(9, 7, new Horse2(7, 9, &cb));
    ChessCreated(9, 8, new Chariot2(8, 9, &cb));
    ChessCreated(7, 1, new Cannon2(1, 7, &cb));
    ChessCreated(7, 7, new Cannon2(7, 7, &cb));
    ChessCreated(6, 0, new Soldier2(0, 6, &cb));
    ChessCreated(6, 2, new Soldier2(2, 6, &cb));
    ChessCreated(6, 4, new Soldier2(4, 6, &cb));
    ChessCreated(6, 6, new Soldier2(6, 6, &cb));
    ChessCreated(6, 8, new Soldier2(8, 6, &cb));
}

void::ChessBoard::ChessCreated(int y, int x, Chess* new_chess) {
    delete Board[get_num(y, x)];
    Board[get_num(y, x)] = new_chess;
    cb.placed(y, x, new_chess->get_mark());
}

char::ChessBoard::MoveChess(int initial_y, int initial_x, int final_y, int final_x) {
    char des_chess{ cb.get_cmark(final_y,final_x) };
    //delete Board[get_num(final_y,final_x)];
    //Board[get_num(final_y,final_x)] = Board[get_num(initial_y,initial_x)];
    switch (cb.get_cmark(initial_y, initial_x)) {
    case 'C':
        ChessCreated(final_y, final_x, new Chariot1(final_x, final_y, &cb));
        break;
    case 'H':
        ChessCreated(final_y, final_x, new Horse1(final_x, final_y, &cb));
        break;
    case 'E':
        ChessCreated(final_y, final_x, new Elephant1(final_x, final_y, &cb));
        break;
    case 'A':
        ChessCreated(final_y, final_x, new Advisor1(final_x, final_y, &cb));
        break;
    case 'G':
        ChessCreated(final_y, final_x, new General1(final_x, final_y, &cb));
        break;
    case 'F':
        ChessCreated(final_y, final_x, new Cannon1(final_x, final_y, &cb));
        break;
    case 'S':
        ChessCreated(final_y, final_x, new Soldier1(final_x, final_y, &cb));
        break;
    case 'c':
        ChessCreated(final_y, final_x, new Chariot2(final_x, final_y, &cb));
        break;
    case 'h':
        ChessCreated(final_y, final_x, new Horse2(final_x, final_y, &cb));
        break;
    case 'e':
        ChessCreated(final_y, final_x, new Elephant2(final_x, final_y, &cb));
        break;
    case 'a':
        ChessCreated(final_y, final_x, new Advisor2(final_x, final_y, &cb));
        break;
    case 'g':
        ChessCreated(final_y, final_x, new General2(final_x, final_y, &cb));
        break;
    case 'f':
        ChessCreated(final_y, final_x, new Cannon2(final_x, final_y, &cb));
        break;
    case 's':
        ChessCreated(final_y, final_x, new Soldier2(final_x, final_y, &cb));
        break;
    default:
        cout << " wrong movement " << endl;
    }
    //get_Chess(final_y,final_x).initial_y = final_y;
    //get_Chess(final_y,final_x).initial_x = final_x;
    Board[get_num(initial_y, initial_x)] = new Empty(initial_y, initial_x, &cb);

    cb.placed(final_y, final_x, Board[get_num(final_y, final_x)]->get_mark());
    cb.placed(initial_y, initial_x, Board[get_num(initial_y, initial_x)]->get_mark());
    return des_chess;
    //cout << "initial_y\t initial_x\t final_y\t final_x" << endl << initial_y << initial_x << final_y << final_x << endl;
    //cout << Board[get_num(final_y,final_x)]->get_mark() << Board[get_num(initial_y,initial_x)]->get_mark() <<endl;
}

bool::ChessBoard::board_mdecision(int initial_y, int initial_x, int final_y, int final_x) {
    bool res_decision = Board[get_num(initial_y, initial_x)]->move_decision(final_x, final_y);
    char initial_char = cb.get_cmark(initial_y, initial_x);
    char final_char = cb.get_cmark(final_y, final_x);
    int initial_team, final_team;
    //cout << "initial_y:"<< initial_y << " initial_x:" << initial_x << " final_y:" << final_y <<" final_x:" << final_x << endl;
    //cout << "final_char:" << final_char << "  initial_char:" << initial_char << endl;
    //cout << "initial_team:" << initial_team << " final_team:" << final_team << endl;
    if (initial_char >= 'a' && initial_char <= 'z')
        initial_team = 2;
    else if (initial_char >= 'A' && initial_char <= 'Z')
        initial_team = 1;
    else
        initial_team = 0;

    if (final_char >= 'a' && final_char <= 'z')
        final_team = 2;
    else if (final_char >= 'A' && final_char <= 'Z')
        final_team = 1;
    else
        final_team = 0;

    if (res_decision && (initial_team + final_team == 3 || final_team == 0))
        return 1;
    else
        return 0;
}

/*
bool::ChessBoard::boardTraversal(int initial_y,int initial_x){
        if(cb.get_cmark(initial_y,initial_x) == '-'){
            cout << "Has no chess on this positon" << endl;
            return 0;
        }
        char c{'0'};
        for(int i{};i<10;i++){
            for(int j{};j<9;j++){
                if(board_mdecision(initial_y,initial_x,i,j)){
                    return 1;
                    cb.cplaced(i,j,c);
                    cout << "position[" << i << "," << j << "]:  " << c << endl;
                    c++;
                }
            }
        }
    }
}
*/

int::ChessBoard::player_turn(int turn_team) {
begin:
    //system("cls");
    //cout << "Player " << turn_team << "'s turn" << endl;
    printChessBoard(turn_team);
    char c_y, c_x;
    char flags[17]{ '0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','&','?' };
    int y, x, input_team, ok{ 0 }, count{ 0 }, selection_num{ -1 };
    bool can_move{ 0 }, selection_check{ 0 };
    char selection, des_chess;
    struct position choices[17];
    cout << "Please input 2 number as the location of the chess you want to move" << endl;
    cout << "x:0~8 , y:0~9" << endl << endl;

    do {
        ok = 0;
        cin >> c_x;
        cout << "Please input y" << endl;
        cin >> c_y;
        y = c_y - '0';
        x = c_x - '0';
        if (y > 9 || y < 0 || x > 8 || x < 0)
        {
            printChessBoard(turn_team);
            cout << "Please input 2 number as the location of the chess you want to move" << endl;
            cout << "x:0~8 , y:0~9" << endl << endl;
            continue;
        }
        if (cb.get_cmark(y, x) == '-') {
            input_team = 0;
        }
        else if (cb.get_cmark(y, x) >= 'a' && cb.get_cmark(y, x) <= 'z')
            input_team = 2;
        else
            input_team = 1;

        if (input_team == 0) {
            printChessBoard(turn_team);
            cout << "Please type 2 numbers as the position of the chess piece you want to move" << endl;
            cout << "x:0~8 , y:0~9" << endl << endl;
            cout << "There is no chess on this positon" << endl;
            cout << "Please type again" << endl;
        }
        else if (input_team != turn_team) {
            printChessBoard(turn_team);
            cout << "Please type 2 numbers as the position of the chess piece you want to move" << endl;
            cout << "x:0~8 , y:0~9" << endl << endl;
            cout << "This is not your chess" << endl;
            cout << "Please type again" << endl;
        }
        else {
            ok = 1;
            for (int i{};i < 10;i++) {
                for (int j{};j < 9;j++) {
                    if (board_mdecision(y, x, i, j)) {
                        cb.cplaced(i, j, flags[count]);
                        choices[count].y = i;
                        choices[count].x = j;
                        can_move = 1;
                        count++;
                    }
                }
            }
            if (can_move == 0) {
                printChessBoard(turn_team);
                cout << "Please type 2 numbers as the position of the chess piece you want to move" << endl;
                cout << "x:0~8 , y:0~9" << endl << endl;
                cout << "This chess can't move" << endl;
                cout << "Please type again" << endl;
            }
        }
    } while (ok == 0 || can_move == 0);

    //traversial chess board,get positions where the chess can go,
    //push back to finaly and finalx
    printChessBoard(turn_team);

    cout << "Select the destination of the chess " << cb.get_cmark(y, x) << "[" << x << "," << y << "]: " << endl;
    cout << "(input \"<\" to choose another chess)" << endl << endl;
    //move the chess
    do {
        cin >> selection;
        if (selection == '<') {
            cb.choices_clean();
            goto begin;
        }
        for (int i{};i < count;i++) {
            if (flags[i] == selection) {
                selection_check = 1;
                selection_num = i;
            }
        }

        if (selection_check == 0) {
            printChessBoard(turn_team);
            cout << "Select the destination of the chess " << cb.get_cmark(y, x) << "[" << x << "," << y << "]: " << endl;
            cout << "(input \"<\" to choose another chess)" << endl << endl;
            cout << "your input is not right" << endl;
            cout << "Please input again" << endl;
        }
    } while (selection_check == 0);

    des_chess = MoveChess(y, x, choices[selection_num].y, choices[selection_num].x);
    cb.choices_clean();
    if (des_chess == 'g')
        return 1;
    else if (des_chess == 'G')
        return 2;
    else
        return 0;
}

void::ChessBoard::printChessBoard(int turn_team) {
    system("cls");
    cout << "*********************************************" << endl;
    cout << "********        Chinese Chess        ********" << endl;
    cout << "*********************************************" << endl << endl;


    cb.cbprint();

    cout << endl;
    //cout << "\t       ===============" << endl;
    cout << "\t       ==  Player" << turn_team << "  ==" << endl;
    cout << "\t       ===============" << endl;
}