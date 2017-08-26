/* 求一个排序数组中，第k个大的数字
 * Solution：解法很多，如桶排序，最小堆（堆的大小是k）
 * Partition,复杂度O(n).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int end = nums.size() -1;
       int start = 0;
       k = nums.size() - k;
       while(1){
            int pos = partition(nums, start, end);
            if(k > pos) {
                start = pos + 1;
            } else if(k < pos){
                end = pos - 1;
            } else {
                return nums[pos];
            }
            
       }
    }

private:
    int partition(vector<int> &nums, int start, int end){
        int pivot = nums[end];
        int small = start - 1;
        for(int i=start; i<end; ++i){
            if(nums[i] < pivot){
                ++small;
                swap(nums[small], nums[i]);
            }
        }

        ++small;
        swap(nums[end], nums[small]);
        return small;
    }
};
