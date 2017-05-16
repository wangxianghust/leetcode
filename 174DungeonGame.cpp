/* 给定一个二维的grid，里面是int,有正（加血）有负（减血），现在有个knight从左上角到右下角，每次只能right和down两个
 * 方向行走，且每步都要保证血量大于1，求knight出发的时候需要的最少血量。
 * Solution：直观上，就是DP，实际也是，重点是，1. 要从右下角向左上角逆推，为啥？（因为右下角是确定的，1，确定状态！）
 * 2.保证每个小方格的血量大于1.
 * 用dp[i][j] 表示到(i,j)的最少血量。
 *
 * 优化：每个与dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - matrix[i][j] 和 1 取 max。使用单行数组即可，不用二维的。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> & dungeon){
        if(dungeon.size() == 0 || dungeon[0].size() == 0) return 0;
        int M(dungeon.size()), N(dungeon[0].size());
        vector<int> least(N+1, INT_MAX);
        least[N-1] = 1;
        for(int m = M-1; m >= 0; --m){
            for(int n = N-1; n >= 0; --n){
                least[n] = max(1, min(least[n], least[n+1]) - dungeon[m][n] );
            }
        }
        return least[0];
    }

    int calculateMinimumHP_(vector<vector<int>>& dungeon) {
        if(dungeon.size() == 0 || dungeon[0].size() == 0) return 0;
        int M(dungeon.size()), N(dungeon[0].size());
        vector<vector<int> > least(M+1, vector<int>(N+1, INT_MAX));
        //for(int m=0; m<=M; ++m) least[m][N] = 1;
        //for(int n=0; n<=N; ++n) least[M][n] = 1;
        //初始化只要least[m+1][n], least[m][n+1]有一个为1即可，其他为INT_MAX，因为只有最后一个有剩余血量为1的
        //需求，其他虚拟的无
        least[M][N-1] = 1;
        for(int m = M-1; m >= 0; --m){
            for(int n = N-1; n >= 0; --n){
                least[m][n] = min(least[m+1][n], least[m][n+1]) - dungeon[m][n];
                least[m][n] = max(least[m][n], 1);
            }
        }
        return least[0][0];
    }
};
