/*给定一个数组和target，求连续子数组和 >= sum 的长度
 * Solution: 经典的双指针问题，找一个全局变量记录即可。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        int ret = 0;
        int start(0), end(0), sum(0);
        for( ; end<size; ++end){
            sum += nums[end];
            if(sum >= s) break;
        }
        if(end == size) return 0;
        ret = end - start + 1;
        while(end < size){
            while(start <= end && sum >= s){
                sum -= nums[start++];
            }
            ret = min(ret, end - start + 2); // end - (start-1) +1
            if(++end < size)sum += nums[end]; //make end++ < size is ok.
        }
        return ret;
    }
};

int main(){
    //AC
}
