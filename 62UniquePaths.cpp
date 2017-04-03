/*问题：给一个matrix, m*n, 从左上角出发，在右下角终点，robot只能right,down运动，求所有Unique path 数量
 * 解答：经典回溯法，注意边界条件即可,当然妥妥的TLE，状态量要爆炸啊
 * 没关系，这时候用DP，DP(m,n) = DP(m-1, n) + DP(m, n-1);
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n){
        int64_t ret[m][n];
        //Initialization
        for(int i=0; i<m; ++i) ret[i][0] = 1;
        for(int i=0; i<n; ++i) ret[0][i] = 1;
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                ret[i][j] = ret[i-1][j] + ret[i][j-1];
            }
        }
        return ret[m-1][n-1];
    }
public:
    int uniquePaths_(int m, int n) {
        int ret = 0;
        int i=1;
        int j=1;
        count(m, n, i, j, ret);
        return ret;
    }

private:
    void count(int m, int n, int i, int j, int &ret){
        if(i>m || j>n) return;
        if(i==m && j==n) ++ret;
        count(m, n, i+1, j, ret);
        count(m, n, i, j+1, ret);
    }
};

int main(){
    freopen("62test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int m, n; cin >> m >> n;
        cout << Sol.uniquePaths(m, n) << endl;
    }
}
