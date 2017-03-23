#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> per;
        unordered_set<int> seen; //use seen to record nums have been added.hash function realize.
        vector<vector<int>> ret;
        int N = nums.size();
        permute(nums, per, seen, ret, N);
        return ret;
    }
private:
    void permute(vector<int> &nums, vector<int> &per, unordered_set<int> &seen, vector<vector<int>> &ret, int N){
        if(per.size() == N){  //the termination condition
            ret.push_back(per);  
            return;
        } 
        for(int i=0; i<N; ++i){
            if(seen.find(nums[i]) == seen.end()){
                seen.insert(nums[i]);
                per.push_back(nums[i]);
                permute(nums, per, seen, ret, N);
                seen.erase(nums[i]);
                per.pop_back();
            }
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

void test(){
    set<int> se{1,2,3};
    for(int i : se) cout << i << endl;
    for(auto iter = se.begin(); iter != se.end();++iter) cout << *iter  << endl;
}

int main(){
    //test();
    freopen("46test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<int> nums;
        for(int j=0; j<size; ++j){
            int c; cin >> c;
            nums.push_back(c);
        }
        auto ret = Sol.permute(nums);
        Sol.print(ret);
    }
}
