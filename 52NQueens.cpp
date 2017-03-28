/*求出NQueens的解
 * 经典的回溯法就可以解决，稍微tricky的地方是，matrix不是用二维矩阵保存的，一维就可以
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> matrix(n, -1);//every row have one queen, the value is the column index.
        int ret = 0;
        solveNQueens(ret, matrix, 0);
        return ret;
    }

private:
    void solveNQueens(int &ret, vector<int> &matrix, int row){
        int size = matrix.size();
        if(row == size){
           ++ret;
           return;
        }
        
        for(int column=0; column<size; ++column){
            if(isValid(matrix, row, column)){
                matrix[row] = column;
                solveNQueens(ret,  matrix, row+1);
                matrix[row] = -1; 
            }
        }
    }

    bool isValid(vector<int> &matrix, int row, int column){
        for(int i=0; i<row; ++i){
            int j = matrix[i]; //get the column of row i
            if(abs(row-i) == abs(column-j) || column == j)  return false;
        }
        return true;
    }
};

int main(){
    freopen("52test.txt", "r", stdin);
    int total; cin >> total;
    //cout << total << endl;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int n; cin >> n; //cout << n << endl;
        auto ret = Sol.totalNQueens(n);
        cout << ret << endl;
    }
}

