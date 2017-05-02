/* 给定一个整型数组，其中有一个元素超过了数组个数的一半，求出这个元素
 * Solution: 可以使用Partition，然后不断的寻找第mid个，期望时间是 O(n)
 * 同时由于个数是超过一半的，所以不断的统计每个数出现的个数也可以，一样times+1, or times-1，到0的时候标记下一个数字
 */

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber_(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if(size < 1) return -1;
        int ret = nums[0];
        int times = 1;
        for(int i=1; i<size; ++i){
            if(times == 0){
                ret = nums[i];
                ++times;
            } else {
                if(ret == nums[i]) ++times;
                else --times;
            }
        }
        return ret;
    }

public:
    int majorityNumber(vector<int> nums){
        int size = nums.size();
        if(size < 1) return -1;
        int mid = size >> 1;
        int start(0), end(size-1);
        int index = myPartition(nums, start, end);
        while(index != mid){
            if(index < mid){
                start = index + 1;
                index = myPartition(nums, start, end);
            } else {
                end = index-1;
                index = myPartition(nums, start, end);
            }
        }
        return nums[mid];
    }
private:
    int myPartition(vector<int> &nums, int start, int end){
        int pivot = nums[end];
        int small = start - 1;
        for(int i=start; i<end; ++i){
            if(nums[i] < pivot){
                ++small;
                if(i != small) swap(nums[i], nums[small]);  // To decrease the nums of swap.
            }
        }
        ++small;
        swap(nums[small], nums[end]);
        return small;
    }
};

