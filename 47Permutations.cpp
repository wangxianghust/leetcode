/*经典的回溯问题，不过还是有问题，line 46的函数为何不可以是 &nums
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &nums){
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        permute(nums, 0, nums.size(), ret);
        return ret;
    }

    vector<vector<int>> permuteUniqui_(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> per;
        vector<vector<int>> ret;
        map<int, int> nums_map; //static the num of each num in nums.
        for(int i : nums) ++nums_map[i];
        permute(nums, per, ret, nums_map);
        return ret;
    }
private:
    //My first sight method
    void permute(vector<int> &nums, vector<int> &per, vector<vector<int> > &ret, map<int,int> nums_map){
        if(per.size() == nums.size()){
            ret.push_back(per);
            return;
        }
        for(auto &num : nums_map){
            if(num.second <= 0) continue;
            per.push_back(num.first);
            --num.second;
            permute(nums, per, ret, nums_map);
            ++num.second;
            per.pop_back();
        }
    }

    //From solution, a in-place and no set.
    void permute(vector<int> nums, int begin, int size, vector<vector<int> > &ret){
        if(begin == size-1){
            ret.push_back(nums);
            return;
        }
        for(int i=begin; i<size; ++i){
            if(i != begin && nums[i] == nums[begin]) continue;
            swap(nums[i], nums[begin]);
            permute(nums, begin+1, size, ret);
            //swap(nums[i], nums[begin]);
        }
    }

public:
    void print(vector<vector<int>> &ret){
        for(auto per : ret){
            for(int i : per)cout << i << " ";
            cout << endl;
        }
        cout << "---" << endl;
    }
};

int main(){
    //test();
    freopen("47test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<int> nums;
        for(int j=0; j<size; ++j){
            int c; cin >> c;
            nums.push_back(c);
        }
        auto ret = Sol.permuteUnique(nums);
        Sol.print(ret);
    }
}

