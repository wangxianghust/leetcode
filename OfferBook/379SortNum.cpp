/* 给定一组数字，求排序后，得到一个最小的数字
 * Solution：这里用到了一个新的排序，就是 如果 a+b < b+a; 则认为 a<b，可以使用反证法证明
 * 使用新的排序得到的数字，从前至后排列起来就可以
 *
 * 方法二是使用回溯法得到所有的结果再排序，指数复杂度不合理
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        int size = nums.size();
        if(size == 0) return NULL;
        vector<string> str;
        for(int i=0; i<size; ++i){
            str.push_back(to_string(nums[i]));
        }
        //sort(str.begin(), str.end(), [](string &a, string &b) { return a+b < b+a; });
        sort(str.begin(), str.end(), cmp);
        string ret;
        for(string i : str) ret += i;
        return ret;
    }

    static bool cmp(string &a, string &b){
        string s1 = a+b;
        string s2 = b+a;
        return s1 < s2;
    }
};

int main(){
    Solution Sol;
    vector<int> nums{3,32,321,5,6,78};
    cout << Sol.minNumber(nums) << endl;

}
