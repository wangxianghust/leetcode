/* 给int n, 求n以内的质数个数，不包括n
 * Solution：首先判定质数的时候，到sqrt(x)就可以进行判断了，但是这题不是这种思路，怎么可能每个数字都要进行一次判定呢？
 * 解法类似于DP，先开一个数组表示是否是质数，false代表质数，true代表非质数（1和合数），然后每次判定一个质数x,则2x, 3x, 4x，kx<n，都是素数
 * 填表法，填完再遍历一遍就可以le
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        int ret = 0;
        vector<bool> state(n, false);
        state[1] = state[0] = true; // 0 1 非质数
        for(int i=2; i<n; ++i){
            if(state[i] == false){
                //两层含义，该状态没有被判定（why?这个数字不能从前面的质数推导到，也就是说是一个质数 ）
                //++ret;
                if(i*i > n) break; //统计完毕，只要统计FALSE的数量即可。
                for(int j=2; i*j<n; ++j){
                    state[i*j] = true;
                }
            }
        }
        ret = count(state.begin(), state.end(), false);
        return ret;
    }
};
