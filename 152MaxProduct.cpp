/*给int数组，寻找连续数组乘积最大
 * Solution：很像最大连续子数组和，区别在哪里？答，还需要多保留一个min,因为min*negative可以再变成
 * 一个max，所以每多计算一个值，都需要保留max和min,同时，先判断A[i]的正负来决定max,min计算
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return -1;
        int min_pro(nums[0]), max_pro(nums[0]), ret(nums[0]);
        for(int i=1; i<size; ++i){
            if(nums[i] < 0) swap(min_pro, max_pro);
            min_pro = min(nums[i], min_pro*nums[i]);
            max_pro = max(nums[i], max_pro*nums[i]);
            ret = max(ret, max_pro);
        }
        return ret;
    }
};
