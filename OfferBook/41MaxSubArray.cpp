/* 求最大子数组和
 * 分治法
 * 可以使用动态规划，if F(i) <= 0; F(i+1) = nums[i+1]; if F(i) > 0, F(i+1) = F(i) + nums(i+1); 
 */

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */

    int maxSubArray(vector<int> nums){
        int ret = INT_MIN;
        int cur_sum(0);
        for(int i=0; i<nums.size(); ++i){
            if(cur_sum <= 0){
                cur_sum = nums[i];
            } else {
                cur_sum += nums[i];
            }

            if(cur_sum > ret) ret = cur_sum; //Global max to update the value.
        }
        return ret;
    }

    int maxSubArray(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if(size == 0) return 0;
        return maxSubArray(nums, 0, size-1);
    }
private:
    int maxSubArray(vector<int> &nums, int left, int right){
        if(left == right) return nums[left];
        int mid = (right-left)/2 + left;
        //Split problem to 2: A[left,...mid]  A[mid+1,... right]
        int left_sum = maxSubArray(nums, left, mid);  // NOTICE, here is mid NOT mid-1;
        int cross_sum = cross(nums, left, mid, right); // must cross the mid point
        int right_sum = maxSubArray(nums, mid+1, right);
        return max(left_sum, max(cross_sum, right_sum));
    }

    int cross(vector<int> &nums, int left, int mid, int right){
        int sum = 0;
        int left_sum = INT_MIN;
        for(int i=mid-1; i>=left; --i){
            sum += nums[i];
            if(sum > left_sum) left_sum = sum;
        }
        left_sum = (left_sum == INT_MIN) ? 0 : left_sum;

        sum = 0;
        int right_sum = INT_MIN;
        for(int i=mid+1; i<=right; ++i){
            sum += nums[i];
            if(sum > right_sum) right_sum = sum;
        }
        right_sum = (right_sum == INT_MIN) ? 0 : right_sum;

        return left_sum + nums[mid] + right_sum;
    }
};
