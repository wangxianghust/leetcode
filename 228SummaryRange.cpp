/* 给定一串数字，不重复，输出其覆盖的连续区间
 * Solution：直接模拟计算
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int size = nums.size();
        if(size == 0) return ret;
        for(int i=0; i<size; ++i){
            int num = nums[i];
            while(i+1 < size && nums[i+1] - nums[i] == 1) ++i;
            if(num != nums[i]) ret.push_back(to_string(num) + "->" + to_string(nums[i]));
            else ret.push_back(to_string(nums[i]));
        }
        return ret;
    }
};

int main(){
    
}
