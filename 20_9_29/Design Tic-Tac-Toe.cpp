#include <bits/stdc++.h>
using namespace std;

class TicTacToe {
   public:
    vector<int> cols;
    vector<int> rows;
    int diagonal = 0;
    int antiDiagonal = 0;
    int size;
    int winner = 0;

    TicTacToe(int n) {
        size = n;
        cols.assign(n, 0);
        rows.assign(n, 0);
    }

    int move(int row, int col, int player) {
        if (winner > 0) {
            return winner;
        }
        int num = player == 1 ? 1 : -1;
        cols[col] += num;
        if (abs(cols[col]) == size) {
            winner = player;
            return winner;
        }

        rows[row] += num;
        if (abs(rows[row]) == size) {
            winner = player;
            return winner;
        }
        if (row == col) {
            diagonal += num;
            if (abs(diagonal) == size) {
                winner = player;
                return winner;
            }
        }
        if (row == size - 1 - col) {
            antiDiagonal += num;
            if (abs(antiDiagonal) == size) {
                winner = player;
                return winner;
            }
        }
        return winner;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */