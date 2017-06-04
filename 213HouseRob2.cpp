/* House Robber 升级，现在house不是在一条直线上，成为了一个圆，报警的规则还是不变的
 * Solution: DP, 两遍DP即可，就是选择第一个还是不选择第一个,选择第一个，则在0~len-2上使用dp，不选择第一个，在1~len-1使用dp
 * 同时在空间上是可以优化的，因为之和前面两个状态有关，所有只需要pre,cur，就是可以求出next,然后pre = cur; cur = next; 继续迭代。
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        int select_first = rob(nums, 0, len-2, 0);
        int not_select_first = rob(nums, 1, len-1, 1);
        cout << "first & not_first" << select_first << " --- " << not_select_first << endl;
        return max(select_first, not_select_first);
    }
private:
    int rob(vector<int> &nums, int start, int end, int offset){
        //when we not select first, there will be an offset of nums index.
        if(end == start) return nums[start];
        if(end == start+1) return max(nums[start], nums[end]);
        int len = end-start+1;
        vector<int> dp(len, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]); 
        for(int i=2; i<len; ++i){
            dp[i] = max(dp[i-2]+nums[i+offset], dp[i-1]);
        }
        return dp[len-1];
    }
};

int main(){
    vector<int> nums{1,1,1,2};
    Solution Sol;
    cout << Sol.rob(nums) << endl;
}
