#pragma once
#pragma once
#include <iostream>
using namespace std;

class c_board {
private:
    char board[10][9];
    char choices[10][9];
public:
    c_board() {
        for (int i{};i < 10;i++)
            for (int j{};j < 9;j++) {
                board[i][j] = '-';
                choices[i][j] = '-';
            }
    }
    void placed(int y, int x, char c) {
        board[y][x] = c;
    }
    void cplaced(int y, int x, char c) {
        choices[y][x] = c;
    }
    char get_cmark(int y, int x) {
        return board[y][x];
    }

    bool occupation(int y, int x) {
        if (board[y][x] == '-')
            return 0;
        else
            return 1;
    }
    void choices_clean() {
        for (int i{};i < 10;i++)
            for (int j{};j < 9;j++) {
                choices[i][j] = '-';
            }
    }


    void cbprint() {
        cout << "\t" << "\\x 0  1  2  3  4  5  6  7  8" << endl;
        cout << "\ty\\" << endl;
        for (int i{};i < 10;i++) {
            cout << "\t" << i << "  ";
            if (i < 9) {
                for (int j{};j < 9;j++) {
                    if (j < 8) {
                        if (board[i][j] != '-')
                            cout << board[i][j] << choices[i][j] << '-';
                        else {
                            if (choices[i][j] != '-')
                                cout << choices[i][j] << "--";
                            else
                                cout << board[i][j] << "--";
                        }
                    }
                    else {
                        if (board[i][j] != '-') {
                            if (choices[i][j] != '-')
                                cout << board[i][j] << choices[i][j] << endl;
                            else
                                cout << board[i][j] << endl;
                        }
                        else {
                            if (choices[i][j] != '-')
                                cout << choices[i][j] << endl;
                            else
                                cout << board[i][j] << endl;
                        }
                    }
                }
                cout << "\t  ";
                if (i == 4)
                    cout << " |     --the River--     |" << endl;
                else
                    cout << " |  |  |  |  |  |  |  |  |" << endl;
            }
            else {
                for (int j{};j < 9;j++) {
                    if (j < 8) {
                        if (board[i][j] != '-')
                            cout << board[i][j] << choices[i][j] << '-';
                        else {
                            if (choices[i][j] != '-')
                                cout << choices[i][j] << "--";
                            else
                                cout << board[i][j] << "--";
                        }
                    }
                    else {
                        if (board[i][j] != '-') {
                            if (choices[i][j] != '-')
                                cout << board[i][j] << choices[i][j] << endl;
                            else
                                cout << board[i][j] << endl;
                        }
                        else {
                            if (choices[i][j] != '-')
                                cout << choices[i][j] << endl;
                            else
                                cout << board[i][j] << endl;
                        }
                    }
                }
            }
        }
        cout << "\t" << "y/" << endl;
        cout << "\t" << "/x 0  1  2  3  4  5  6  7  8" << endl;

    }
};


