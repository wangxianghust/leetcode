#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ret = true;
        int size = board.size();
        //test row
        for(int i=0; i<size; ++i){
            unordered_set<char> seen;
            for(int j=0; j<size; ++j){
                if(board[i][j] == '.') continue;
                if(seen.find(board[i][j]) == seen.end()){
                    seen.insert(board[i][j]);
                } else {
                    return false;
                }
            }
        }
        
        //test column
        for(int i=0; i<size; ++i){
            unordered_set<char> seen;
            for(int j=0; j<size; ++j){
                if(board[j][i] == '.') continue;
                if(seen.find(board[j][i]) == seen.end()){
                    seen.insert(board[j][i]);
                } else {
                    return false;
                }
            }
        }

        //test sub-box
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                unordered_set<char> seen;
                for(int k=i*3; k<(i+1)*3; ++k){
                    for(int m=j*3; m<(j+1)*3; ++m){
                        char c = board[k][m];
                        if(c == '.') continue;
                        if(seen.find(c) == seen.end()){
                            seen.insert(c);
                        } else {
                            return false;
                        }
                    }
                }
            }
        } 

        return ret;
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
    freopen("36test.txt", "r", stdin);
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
        auto ret = Sol.isValidSudoku(board);
        cout << ret << endl;
    }
}





