#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> sub;
        subsets(nums, sub, ret, 0);
        return ret;
    }

private:
    void subsets(vector<int> &nums, vector<int> &sub, vector<vector<int> > &ret, int begin){
        ret.push_back(sub);
        for(int i=begin; i<nums.size(); ++i){
            sub.push_back(nums[i]);
            subsets(nums, sub, ret, i+1);
            sub.pop_back();
        }
    }
public:
    void print(vector<vector<int> > &ret){
        for(auto sub : ret){
            for(int i : sub)cout << i << " ";
            cout << endl;
        }
        cout << "----" << endl;
    }
};

int main(){
    freopen("78test.txt", "r", stdin);
    int total; cin >>total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<int> nums;
        for(int j=0; j<size; ++j){
            int c; cin >> c;
            nums.push_back(c);
        }
        auto ret = Sol.subsets(nums);
        Sol.print(ret);
    } 
}
