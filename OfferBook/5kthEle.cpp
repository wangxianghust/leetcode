/* 求一个数组中第K大的数字
 * Solution：方法很多，常用的如用Partition求解
 * 2.构建一个最小堆，堆的大小是k,然后对剩下的(n-k)个元素来维护该堆，ele > heap,insert; ele < heap, ignore.
 * 3.使用hash,统计每个数字出现的数量，然后从最大值向小遍历
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int size = nums.size();
        if(size < 1 || size < k || k < 0) return -1;
        int _k = size-k; // the index of k_th.
        int start(0), end(size-1);
        int index = myPartition(nums, start, end);
        while(index != _k){
            if(index > _k){
                end = index-1;
                index = myPartition(nums, start, end);
            } else {
                start = index+1;
                index = myPartition(nums, start, end);
            }
        }
        return nums[index];
    }
private:
    int myPartition(vector<int> &nums, int start, int end){
        int pivot = nums[end];
        int small = start - 1;
        for(int i=start; i<=end; ++i){
            if(nums[i] < pivot){
                ++small;
                if(i != small) swap(nums[i], nums[small]);
            }
        }
        ++small;
        swap(nums[small], nums[end]);
        return small;
    }
};
