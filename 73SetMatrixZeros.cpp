/*Problem:如果某个元素为0，则将其所在的行，列全部置0，In-Place
 *解法：先遍历一遍，记录所有0所在的行，列index, 然后再次遍历
 *如上的解法并不是in-place的，我们可以这样，在遍历的时候，一旦发现matrix[i][j] == 0
 *则将这个信息记录在matrix[i][0], matrix[0][j]=0(因为这两个元素必为0)，同时提前判断row0和col0是否含0
*/

#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        if(rows == 0) return;
        int columns = matrix[0].size();
        bool row_0 = false;
        bool col_0 = false;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0) row_0 = true;
                    if(j == 0) col_0 = true;
                }
            } 
        }

        for(int i=1; i<rows; ++i){
            if(matrix[i][0] == 0){
                for(int j=1; j<columns; ++j){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=1; j<columns; ++j){
            if(matrix[0][j] == 0){
                for(int i=1; i<rows; ++i){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row_0){
            for(int j=0; j<columns; ++j) matrix[0][j] = 0;
        }

        if(col_0){
            for(int i=0; i<rows; ++i) matrix[i][0] = 0;
        }

    }

    //This is not the in-place method though it give the right answer.
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        set<int> rows;
        set<int> columns;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }

        for(int i : rows){
            for(int j=0; j<n; ++j) matrix[i][j] = 0;
        }

        for(int j : columns){
            for(int i=0; i<m; ++i) matrix[i][j] = 0;
        }
    }
};
