/* 找到未排序数组中超过 1/3 的元素
 * Boyer-Moore vote algorithm, 修改版，先假定任意两个，用投票方法
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1(0), count2(0), can1(0), can2(1);
        for(int num : nums){
            if(can1 == num){
                count1++;
            } else if(can2 == num){
                count2++;
            } else if(count1 == 0){
                can1 = num;
                count1 = 1;
            } else if(count2 == 0){
                can2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(int num : nums){
            if(num == can1) count1++;
            if(num == can2) count2++;
        }
        vector<int> ret;
        if(count1 > nums.size()/3) ret.push_back(can1);
        if(count2 > nums.size()/3) ret.push_back(can2);
        return ret;
    }
};

int main(){
    
}
