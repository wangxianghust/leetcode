/* 数组中，求两个数字之和为target,假设只有一组符合，返回两个下标
 * Solution: 用hash去做，map<int, int> 即 map<target-nums[i], index>
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> ret;
        unordered_map<int, int> book;
        for(int i=0; i<nums.size(); ++i){
            if(book.find(nums[i]) == book.end()){
                book.insert({target-nums[i], i});
            } else {
                int index2 = i;
                int index1 = book[nums[i]];
                ret.push_back(index1+1);
                ret.push_back(index2+1);
                break;
            }
        }
        return ret;
    }
};

