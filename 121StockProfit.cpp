/*给定一个数组，求出最大利润，只能有一次的买卖
 * 形式化一下就是，从数组中找两个数字的差最大(小的数字在前，大的在后面)
 * Solution:可以转化为最大子数组问题，回归最大子数组问题，dp[i]表示到i的数组和，dp[i] = (dp[i-1] > 0)? (dp[i-1]+a[i], a[i]);
 * 此处子数组的元素是原来相邻元素的差，当dp[i-1]<0--> dp[i-1] = 0;
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_max(0), ret(0);
        for(int i=1; i<prices.size(); ++i){
            cur_max = max(0, cur_max + prices[i]-prices[i-1]);//cur_max will exist till smaller than 0, and reset to 0.
            if(cur_max > ret) ret = cur_max;
        }
        return ret;
    }
};
