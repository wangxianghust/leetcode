/*问题：给一个matrix, m*n, 从左上角出发，在右下角终点，robot只能right,down运动，求所有Unique path 数量
 * 输入是一个二维矩阵，0可以通过，1表示障碍物
 * 解答：修改DP，initialization要修改，1后面count为0，DP要判断1状态,是1则ret=0, else DP sum
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int64_t ret[m][n];
        //initialization
        int i=0;
        while(i<n && obstacleGrid[0][i] != 1) ret[0][i++] = 1;
        while(i<n) ret[0][i++] = 0;
        i=0;
        while(i<m && obstacleGrid[i][0] != 1) ret[i++][0] = 1;
        while(i<m) ret[i++][0] = 0;
        
        for(i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(obstacleGrid[i][j] == 1) ret[i][j] = 0;
                else ret[i][j] = ret[i-1][j] + ret[i][j-1];
            }
        }
        return ret[m-1][n-1];
    }
};

int main(){
    freopen("63test.txt", "r", stdin);
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
        cout << Sol.uniquePathsWithObstacles(matrix) << endl;
    }
}
