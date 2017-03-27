/*求出NQueens的解*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > solveNQueens(int n) {
        vector<int> matrix(n, -1);//every row have one queen, the value is the column index.
        vector<vector<int> > ret;
        solveNQueens(ret, matrix, 0);
        return ret;
    }

private:
    void solveNQueens(vector<vector<int> > &ret, vector<int> &matrix, int row){
        int size = matrix.size();
        if(row > size){
           ret.push_back(matrix);
           for(int &i:matrix) i = -1;
           return;
        }
        for(int i=row; i<size; ++i){
            for(int j=0; j<size; ++j){
                if(isValid(matrix, i, j)){
                    matrix[i] = j;
                    solveNQueens(ret, matrix, row+1);
                    matrix[i] = -1;
                    //cout << matrix[i] << endl;
                }
            }
        }
    }

    bool isValid(vector<int> &matrix, int row, int column){
        int size = matrix.size();
        for(int i=0; i<size; ++i){
            int j = matrix[i]; //get the column of row i
            if(abs(j-i) == abs(row-column) || column == j)  return false;
        }
        return true;
    }
public:
    template<typename T>
        void print(vector<vector<T> > ret){
            for(auto item : ret){
                for(T i : item){
                    cout << i << " ";
                }
                cout << endl;
            }
            cout << "---" << endl;
        }
};

int main(){
    freopen("51test.txt", "r", stdin);
    int total; cin >> total;
    //cout << total << endl;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int n; cin >> n; //cout << n << endl;
        auto ret = Sol.solveNQueens(n);
        Sol.print(ret);
    }
}
