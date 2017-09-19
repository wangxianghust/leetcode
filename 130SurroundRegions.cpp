/* 给出一堆XXOO组成的二维矩阵，发现被X包围的O,并将O变成X.
 * 直接的想法是，什么叫被X包围？答，1. O在边界上不会被包围 2. 和未被包围的O相连接的O未被包围。
 * 这里有关键的关系，相连接的是一组，所以想到使用并查集，把边界的O和X放在一个集合叫做Union，相连接的O放在一起
 * 最后遍历，发现没有和X连接的，都是未被包围的节点。
 *
 * 最后采用的解法：1.先寻找边界上的O，并将于O相连接的O用Y表示； 2. 进行遍历，O变换成 X，Y 变换成 O
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int row = board.size();
        int col = board[0].size();
        //calculate first row and last row.
        for(int i=0; i<row; ++i){
            check(board, i, 0, row, col);
            if(col > 1) check(board, i, col-1, row, col);
        }
        //calculate first col and last col, left-most and right-most is considered.
        for(int j=1; j<col-1; ++j){
            check(board, 0, j, row, col);
            if(row > 1) check(board, row-1, j, row, col);
        }

        for(auto &eles : board){
            for(auto &ele : eles){
                if(ele == 'O') ele = 'X';
            }
        }


        for(auto &eles : board){
            for(auto &ele : eles){
                if(ele == 'Y') ele = 'O';
            }
        }
    }

    void check(vector<vector<char>> &board, int i, int j, int row, int col){
        if(board[i][j] == 'O'){
            board[i][j] = 'Y';
            //here is NOT i+1 <= row, visit the wall of board is not allowed.
            if(i+1 < row) check(board, i+1, j, row, col);
            if(i-1 > 0) check(board, i-1, j, row, col);
            if(j+1 < col) check(board, i, j+1, row, col);
            if(j-1 > 0) check(board, i, j-1, row, col);
        }
    }
};
