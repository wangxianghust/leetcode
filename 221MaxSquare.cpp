/* 给定一个矩阵，都是由0和1组成，求全由1组成的正方形，最大面积
 * DP[m][n] : 表示如果选中这个点，能够组成的组大矩阵（此处为边长），当matrix(i,j) = 0, DP(i,j) = 0
 * matrix(i,j) = 1; DP(i,j) = min( DP(i-1, j), DP(i, j-1), DP(i-1, j-1) ) + 1;
 * 此处题解的空间可以继续优化
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m(matrix.size()), n(matrix[0].size());
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_edge = 0; //global max_edge;
        //handle the board
        for(int i=0; i<m; ++i){
            dp[i][0] = matrix[i][0] - '0';
            max_edge = max(max_edge, dp[i][0]);
        }
        for(int j=0; j<n; ++j){
            dp[0][j] = matrix[0][j] - '0';
            max_edge = max(max_edge, dp[0][j]);
        }

        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    dp[i][j] = min( dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) ) + 1;
                }
                max_edge = max(max_edge, dp[i][j]);
            }
        }
        return max_edge*max_edge;
    }
};

int main(){
    
}
