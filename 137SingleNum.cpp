/*给定一个整数数组，除一个元素出现一次外，其他的都出现三次，求这个出现一次的数字
 * Solution:这里有一个通用的解法，int是32bit,每次对一个bit进行处理，求nums中所有数字在该位上1的数量和，
 * 然后 num_1 % 3, 表示的及时single number上的bit是否是1。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size(nums.size());
        int ret(0);
        if(size == 0) return -1;
        for(int i=0; i<32; ++i){
            int sum(0);
            for(int j=0; j<size; ++j){
                if( (nums[j]>>i) & 0x1) ++sum;
            }
            sum %= 3;
            if(sum) ret |= (1u << i); 
        }
        return ret;      
    }
};

int main(){
}

