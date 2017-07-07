/*从0，1，2...n中抽取几个数字组成一个数组，求这个数组中缺少的数字是哪个
 * Solution：1.排序，不过nlgn
 * 2.遍历数组，对每个位置i,如果 num[i] == i or num[i] >= num.size()， stop
 *   否则不断的将num[i]和其正确的位置交换，即 swap(num[i], num[ num[i]  ])
 *   最后遍历数组，得到第一个不正确位置的数字即答案。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        for(int i=0; i<size; ++i){
            while(nums[i] < size && nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
            }           
        }

        for(int i=0; i<size; ++i){
            if(nums[i] != i)return i;
        }

        return size;
    }
};

int main(){
    //AC
}
