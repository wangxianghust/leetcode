/*Problem:给定一个char matrix, 判断word是否可以通过matrix得到
 * 方法：dfs
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) return false;
        int row = board.size();  
        int col = board[0].size();
        bool ret = false;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                //if(board[i][j] == word[0]){
                    ret = dfs(board, row, col, i, j, 0, word);
                    if(ret) return true;
                //}
            }
        }
        return ret;
    }

    bool dfs(vector<vector<char>> &board, int row, int col, int i, int j, int step, string word){
        if(step == word.size()) return true;
        if(i<0 || i>=row || j<0 || j>=col || board[i][j] != word[step] || board[i][j] == '0') return false;
        
        char tmp = board[i][j]; //cause the item may not use more than once, so, we flag the used then recover it.
        board[i][j] = '0';
        if(dfs(board, row, col, i-1, j, step+1, word)) return true;
        if(dfs(board, row, col, i, j-1, step+1, word)) return true;
        if(dfs(board, row, col, i, j+1, step+1, word)) return true;
        if(dfs(board, row, col, i+1, j, step+1, word)) return true;
        board[i][j] = tmp;
        return false;
    }
};

int main(){
    //AC
}
