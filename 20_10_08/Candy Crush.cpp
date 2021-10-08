#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool crush(vector<vector<int>>& board) {
        bool found = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 0) {
                    continue;
                }
                int i_ = i + 1;
                while (i_ < board.size() && abs(board[i][j]) == abs(board[i_][j])) {
                    i_++;
                }
                if (i_ - i > 2) {
                    found = true;
                    for (int k = i; k < i_; k++) {
                        board[k][j] = -abs(board[i][j]);
                    }
                }
                int j_ = j + 1;
                while (j_ < board[0].size() && abs(board[i][j]) == abs(board[i][j_])) {
                    j_++;
                }
                if (j_ - j > 2) {
                    found = true;
                    for (int k = j; k < j_; k++) {
                        board[i][k] = -abs(board[i][j]);
                    }
                }
            }
        }
        return found;
    }

    void gravity(vector<vector<int>>& board) {
        int row = board.size();
        int column = board[0].size();
        for (int j = 0; j < column; j++) {
            int targetRow = row - 1;
            for (int i = row - 1; i >= 0; i--) {
                if (board[i][j] > 0) {
                    board[targetRow--][j] = board[i][j];
                }
            }
            while (targetRow >= 0) {
                board[targetRow--][j] = 0;
            }
        }
    }

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (crush(board)) {
            gravity(board);
        }

        return board;
    }
};