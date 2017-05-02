/*顺时针打印1~n*n的所有数字
 * Solution: 模拟走路即可
 */

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        if(n == 0) return vector<vector<int> >();
        vector<vector<int> > ret(n, vector<int>(n,0));
        int top(0), bottom(n-1), left(0), right(n-1);
        long count = 1;
        while(count <= n*n){
            for(int col=left; col<=right; ++col) ret[top][col] = count++;
            if(++top > bottom) break;

            for(int row=top; row<=bottom; ++row) ret[row][right] = count++;
            if(--right < left) break;

            for(int col=right; col>=left; --col) ret[bottom][col] = count++;
            if(--bottom < top) break;

            for(int row=bottom; row>=top; --row) ret[row][left] = count++;
            if(++left > right) break;
        }
        return ret;
    }
};
