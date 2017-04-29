/* 分割一个数组，奇数在前，偶数在后
 * Solution： 经典的双指针问题吧
 */

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int start(0), end(nums.size()-1);
        while(start < end){
            while(start < end && nums[start] & 0x1){
                ++start;
            } 
            while(start < end && !(nums[end] & 0x1)){
                --end;
            }
            if(start < end){
                swap(nums[start], nums[end]);
                ++start;
                --end;
            }
        }
    }
};
