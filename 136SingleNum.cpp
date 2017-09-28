/*给定一个整数数组，除一个元素出现一次外，其他的都出现两次，求这个出现一次的数字
 * Solution:遍历一遍依次异或就可以
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int num : nums) ret ^= num;
        return ret;
    }
};
