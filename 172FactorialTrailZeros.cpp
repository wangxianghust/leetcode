/* 给定一个数字n, 求 n! 中尾巴中0的数量
 * Solution：不难发现，就是求1~n中每个数包含因子5的数量
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ret(0);
        while(n){
            ret += n/5;
            n /= 5;
        }
        return ret;
    }
};
