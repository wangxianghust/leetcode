/*问题：给一个matrix, m*n, 从左上角出发，在右下角终点，robot只能right,down运动
 * 输入是一个二维矩阵，非负整数，求sum最小的path
 * 解答：和前两题很像，DP， DP(i, j) = matix[i][j] + min(DP[i-1][j], DP[i][j-1])
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int64_t ret[row][col];
        //Initialization
        ret[0][0] = grid[0][0];
        for(int i=1; i<row; ++i){
            ret[i][0] = ret[i-1][0] + grid[i][0];
        }
        for(int j=1; j<col; ++j){
            ret[0][j] = ret[0][j-1] + grid[0][j];
        }

        for(int i=1; i<row; ++i){
            for(int j=1; j<col; ++j){
                ret[i][j] = grid[i][j] + min(ret[i][j-1], ret[i-1][j]);
            }
        }
        return ret[row-1][col-1];
    }
};

int main(){
    freopen("64test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int m, n; cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n,0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int c; cin >> c;
                matrix[i][j] = c;
            }
        }
        cout << Sol.minPathSum(matrix) << endl;
    }
}

