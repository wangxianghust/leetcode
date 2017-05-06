/* 给定一个输入流，没输入要给新的数字，求当前所有数字的中位数
 * Solution: 这题的解法很多，最终选择的是构造两个heap,即一个最大堆和一个最小堆来完成，
 * 对于Insert，当两个heap的大小相同时，插入min-heap，同时要保证最小堆的最小值是大于最大堆的最大值，
 * 所以要先检查新来的ele和max[0], if ele<max[0], 那么把max[0]插入min-heap, ele insert to max-heap。
 * 关键点就是左边max-heap,右边min-heap，最后media必定和两个堆顶元素有关。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> //great<T>..

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> ret;
        int size = nums.size();
        if(size == 0) return ret;
        for(int i=0; i<size; ++i){
            insert(nums[i]);
            ret.push_back(calculate());
        }
        return ret;
    }
public:
    void insert(int ele){
        int min_len(min.size()), max_len(max.size());
        if( ((min_len + max_len) & 0x1)  == 0){ //the sum is even, insert ele to min-heap.
            if(max.size()>0 && ele < max[0]){
                max.push_back(ele);
                push_heap(max.begin(), max.end(), less<int>());
                ele = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(ele);
            push_heap(min.begin(), min.end(), greater<int>());         
        } else {
            if(min.size()>0 && ele > min[0]){
                min.push_back(ele);
                push_heap(min.begin(), min.end(), greater<int>());
                ele = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(ele);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    int calculate(){
        int min_len(min.size()), max_len(max.size());
        int ret = 0;
        if( ((min_len + max_len) & 0x1)  == 0){
            ret = (max[0] + min[0])/2;
        } else {
            ret = min[0];
        }
        return ret;
    }
private:
    vector<int> min;
    vector<int> max;
};

int main(){
    vector<int> nums{1,5,6,10,12};
    Solution Sol;
    auto ret = Sol.medianII(nums);
    for(auto i:ret) cout << i << " ";
}
