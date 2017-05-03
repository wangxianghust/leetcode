/* 求出第n个丑数，丑数的定义是只有2，3，5这三个因子
 * Solution：如果从1开始，一个一个的判定是不是丑数，复杂度高
 * 替代方案是，我们不断的生成新的丑数，直到第n个：如何生成next丑数呢？当前求得的丑数乘2，得到第一个大于当前所有的丑数
 * 同理乘3，乘5，将得到的三个丑数比较，取出最小的即可。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        vector<int> ret;
        ret.push_back(1);
        if(n == 1) return 1;
        for(int i=2; i<=n; ++i){
            int last = ret.back();
            int M2(0), M3(0), M5(0);
            for(int i : ret){
                if(i * 2 > last) {
                    M2 = 2 * i;
                    break;
                }
            }

            for(int i : ret){
                if(i * 3 > last) {
                    M3 = 3 * i;
                    break;
                }
            }
            
            for(int i : ret){
                if(i * 5 > last) {
                    M5 = 5 * i;
                    break;
                }
            }

            int next =  min(M2, min(M3, M5));
            ret.push_back(next);
        }
        return ret.back();
    }
};

int main(){
    Solution Sol;
    Sol.nthUglyNumber(9);
}
