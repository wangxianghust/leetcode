/*顺时针打印矩阵
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        // Write your code here
        vector<int> ret;
        if(matrix.size()== 0 || matrix[0].size() == 0) return ret;
        int top(0), bottom(matrix.size()-1), left(0), right(matrix[0].size()-1);

        while(true){
            for(int col=left; col <= right; ++col) ret.push_back(matrix[top][col]);
            if(++top > bottom) break;

            for(int row=top; row <= bottom; ++row) ret.push_back(matrix[row][right]);
            if(--right < left) break;

            for(int col=right; col >= left; --col) ret.push_back(matrix[bottom][col]);
            if(--bottom < top) break;

            for(int row=bottom; row >= top; --row) ret.push_back(matrix[row][left]);
            if(++left > right) break;

        }
        
        return ret;
    }
};
