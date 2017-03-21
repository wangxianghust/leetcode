#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       solve(board, 0, 0); 
    }
private:
    bool solve(vector<vector<char> > &board, int row, int col){
        //border process
        if(row == 9) return true; //all over.
        if(col == 9) return solve(board, row+1, 0); //a row is over, start a new row.
        if(board[row][col] != '.') return solve(board, row, col+1); //go on
        for(char c='1'; c<='9'; ++c){
            if(isValid(board, row, col, c)){
                board[row][col] = c;
                if(solve(board, row, col+1)) return true;  //test if next ceil is suitable.
                board[row][col] = '.'; //the last is false, replace to old value.
            }            
        }
        return false;
    }
private:
    bool isValid(vector<vector<char> > &board, int i, int j, char c){
        for(int k=0; k<9; ++k) if(board[i][k] == c) return false;
        for(int k=0; k<9; ++k) if(board[k][j] == c) return false;
        int row = i-i%3;
        int col = j-j%3;
        for(int k=0; k<3; ++k){
            for(int m=0; m<3; ++m){
                if(board[row+k][col+m] == c)return false;
            }
        }
        return true;
    }
};

template<class T>
void print(vector<vector<T> > nums){
    for(auto i : nums) {
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    freopen("37test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size = 9;
        vector<vector<char> > board;
        for(int i=0; i<size; ++i){
            vector<char> row;
            for(int j=0; j<size; ++j){
                char c;
                cin>>c;
                row.push_back(c);
            }
            board.push_back(row);
        }
        print(board);
        Sol.solveSudoku(board);
        print(board);
    }
}






