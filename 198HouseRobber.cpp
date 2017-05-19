/* robber问题，连续的数组，但是不能抢连续的两家
 * Solution：经典的DP，dp[i] 表示到第i家最大的收益，则 dp[i] = max( dp[i-2]+A[i] , dp[i-1] )
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,0);
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<size; ++i){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[size-1];
    }
};
