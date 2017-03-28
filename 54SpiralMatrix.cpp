/*问题：螺旋式的输出一个矩阵
 * 思路：在不同的边界条件下，模拟上下左右的操作，同时，
 * 对于访问过的元素用INT_MIN保存，这也是边界。
 */
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        char direction = 'r';
        vector<int> ret;
        int row = matrix.size();
        if(row == 0) return ret;
        int column = matrix[0].size();
        if(column == 0) return ret;

        int count = row * column;
        int i=0;
        int j=0;
        while(count > 0){
            switch(direction){
                case 'r':
                    ret.push_back(matrix[i][j]);
                    matrix[i][j] = INT_MIN;
                    if(j+1<column && matrix[i][j+1] != INT_MIN){
                        ++j;
                    } else {
                        direction = 'd';
                        ++i;
                    }
                    break;

                case 'd':
                    ret.push_back(matrix[i][j]);
                    matrix[i][j] = INT_MIN;
                    if(i+1<row && matrix[i+1][j] != INT_MIN){
                        ++i;
                    } else {
                        direction = 'l';
                        --j;
                    }
                    break;

                case 'l':
                    ret.push_back(matrix[i][j]);
                    matrix[i][j] = INT_MIN;
                    if(j-1>=0 && matrix[i][j-1] != INT_MIN){
                        --j;
                    } else {
                        direction = 'u';
                        --i;
                    }
                    break;

                case 'u':
                    ret.push_back(matrix[i][j]);
                    matrix[i][j] = INT_MIN;
                    if(i-1>=0 && matrix[i-1][j] != INT_MIN){
                        --i;
                    } else {
                        direction = 'r';
                        ++j;
                    }
                    break;
            }
            --count;
        }
        return ret;
    }
};

int main(){
    //AC
}
