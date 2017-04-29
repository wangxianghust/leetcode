/* 寻找旋转数组中的最小值，如4 5 6 7 0 1 2 结果是0
 * Solution: 观察原来数组，是排序的，然后再某个位置进行了折返，排好序的想到二分查找，
 * 如何继续查找？-->通过和首位数字比较判断
 * 何时查找到了？相邻的两个节点，左边的大于首位数字，右边的小于，return 右边的。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        int size = nums.size();
        if(size == 1)return nums[0];
        if(nums[0] < nums[size-1]) return nums[0]; //handle the order case, eg. 1 2 3 4 5
        int low(0), high(size-1), mid(0);
        while(low <= high){
            mid = low + ((high-low)>>1);
            if(nums[mid] < nums[0]){
                if(nums[mid-1] > nums[0]) break;
                else high = mid-1; 
            } else {
                low = mid+1;
            }
        }
        return nums[mid];
    }
};
