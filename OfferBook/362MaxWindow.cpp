/* 给定一个数组，size 为M，给定一个窗口大小N,从头开始遍历数组，求窗口内的最大值集合
 * Solution: 很明显有一个O(MN)的算法，此处采用deque,只用O(M),使用观察法，不断删除前后端的元素
 * 注意的是deque中保存的是下标，理由一是下标信息量丰富，可以算出值同时可以看出是否超出了窗口大小。
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> ret;
        int size = nums.size();
        if(k < 1 || size < 1 || size < k) return ret;
        //handle first k
        deque<int> index;
        for(int i=0; i<k; ++i){
            while(!index.empty() && nums[i] >= nums[index.back()]) index.pop_back();
            index.push_back(i);
        }

        for(int i=k; i<size; ++i){
            ret.push_back(nums[index.front()]);
            while(!index.empty() && nums[i] >= nums[index.back()]) index.pop_back();
            if(!index.empty() && (i-index.front())+1>k) index.pop_front();
            index.push_back(i);
        }
        ret.push_back(nums[index.front()]);
        return ret;
    }
};
