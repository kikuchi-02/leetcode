#include <bits/stdc++.h>

#include <queue>
using namespace std;

class SnakeGame {
   public:
    vector<vector<int>> foods;
    int foodI = 0;
    int colSize;
    int rowSize;
    int col = 0;
    int row = 0;
    int size = 0;
    queue<vector<int>> positions;

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        colSize = width;
        rowSize = height;
        foods = food;
    }

    int move(string direction) {
        positions.push({row, col});

        if (direction == "R") {
            col++;
            if (col > colSize - 1) {
                return -1;
            }
        } else if (direction == "D") {
            row++;
            if (row > rowSize - 1) {
                return -1;
            }
        } else if (direction == "L") {
            col--;
            if (col < 0) {
                return -1;
            }
        } else {
            row--;
            if (row < 0) {
                return -1;
            }
        }
        if (foodI < foods.size()) {
            if (foods[foodI][0] == row && foods[foodI][1] == col) {
                size++;
                foodI++;
                return size;
            }
        }

        if (positions.size() > size) {
            positions.pop();
        }

        queue<vector<int>> que;
        while (!positions.empty()) {
            auto f = positions.front();
            positions.pop();
            if (f[0] == row && f[1] == col) {
                return -1;
            }
            que.push(f);
        }
        positions = que;

        return size;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */