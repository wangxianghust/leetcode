/*问题：数组中的每个数字代表可以跳跃的最大距离，则从0开始，经过几个step可以跳到最后
 * 解法：回溯，然后选取最优解,不过TLE了
 * 新方法：BFS，每一次准备jump时候，确定这一跳能跳到的最远（[cur_begin, cur_end])决定
 */

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums){
        if(nums.size() < 2) return 0;
        int cur_end = 0;  //the range we can get
        int cur_farest = 0; //in cur_index range, the farest we can get
        int level = 0;
        for(int i=0; i<nums.size()-1; ++i){ //the last node should not jump to others, so.
            cur_farest = max(cur_farest, nums[i]+i);
            if(i == cur_end){ //BFS, we walk one layer.i is READY to jump.
                ++level;
                cur_end = cur_farest;
            }
        }
        return level;
    }
public:
    int jump_(vector<int>& nums) {
        choose(nums, 0, 0);
        return best;
    }

public:
    Solution():best(INT_MAX){}
    int best;

private:
    void choose(vector<int> &nums, int index, int step){
        if(index >= nums.size()-1){
            if(step < best) best = step;
            //cout << endl;
            return;
        }
        if(nums[index] == 0) return;
        for(int i = index+1; i <= index+nums[index]; ++i){
            //cout << nums[i] << "-->";
            choose(nums, i, step+1);
        }
    }
};

int main(){
    freopen("45test.txt", "r", stdin);
    int total; cin >> total;
    for(int i=0; i<total; ++i){
        Solution Sol;
        int size; cin >> size;
        vector<int> nums;
        for(int i=0; i<size; ++i){
            int c; cin >> c;
            nums.push_back(c);
        }
        int ret = Sol.jump(nums);
        cout << ret << endl;
    }
}
