/* * 问题：Jump Game, 数组中的元素代表能够跳到的最远距离，判断是否能够到达最后节点
 * 方法：遍历每个点，每次都update这个点能够jump的最远距离，一旦这个点是之前所有点（包含这个点）
 * 所能跳到的最远距离，停止
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_farest = 0;
        int size = nums.size();
        for(int i=0; i<size-1; ++i){ // Notice, there is size-1, cause the last node should not jump
            cur_farest = max(cur_farest, nums[i] + i);
            if(i == cur_farest) return false; // the condition.
        }
        return true;
    }
};

int main(){
    freopen("55test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<int> nums;
        for(int j=0; j<size; ++j){
            int c; cin >> c;
            nums.push_back(c);
        }

        bool ret = Sol.canJump(nums);
        cout << ret << endl;
    }
}

