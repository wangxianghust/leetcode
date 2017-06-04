/*判断数组是否有重复的数字
 * Solution：方法很多，使用，set,bucket排序等等
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> si(nums.begin(), nums.end());
        return nums.size() > si.size();
    }
};
