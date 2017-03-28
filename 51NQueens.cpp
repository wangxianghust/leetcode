/*求出NQueens的解
 * 经典的回溯法就可以解决，稍微tricky的地方是，matrix不是用二维矩阵保存的，一维就可以
 */
#include <vector>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> matrix(n, -1);//every row have one queen, the value is the column index.
        vector<vector<int> > ret;
        vector<vector<string> > output;
        solveNQueens(ret, matrix, 0);
        convert(ret, output, n);
        return output;
    }

private:
    void convert(vector<vector<int> > &ret, vector<vector<string> > &output, int n){
        for(auto item : ret){ //every item is a solution.
            vector<string> lines;
            for(int i=0; i<n; ++i){
                string line(n, '.');
                int column = item[i];
                line[column] = 'Q';//put the Q
                lines.push_back(line);
            }
            output.push_back(lines);
        }
    }

    void solveNQueens(vector<vector<int> > &ret, vector<int> &matrix, int row){
        int size = matrix.size();
        if(row == size){
           ret.push_back(matrix);
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
public:
    template<typename T>
        void print(vector<vector<T> > ret){
            for(auto item : ret){
                for(T i : item){
                    cout << i << endl;
                }
                cout << "Another soluton" << endl;
            }
            cout << "---------" << endl;
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
