#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

vector<int> twoSum(vector<int> &nums, int target){
    vector<pair<int,int> > nums_sort;
    for(int i=0; i<nums.size(); ++i){
        nums_sort.push_back(make_pair(i, nums[i]));
    }
    vector<int> ret(2);
    sort(nums_sort.begin(), nums_sort.end(), cmp);
    int i = 0;
    int j = nums.size() - 1;
    while(i < j){
        int sum = nums_sort[i].second + nums_sort[j].second;
        if(sum == target) {
            ret[0] = nums_sort[i].first;
            ret[1] = nums_sort[j].first;
            break;
        } else if(sum < target){
            ++i;
        } else {
            --j;
        }
    }
    return ret;
}

vector<int> twoSum_(vector<int> &nums, int target){
    unordered_map<int, int> m;
    vector<int> ret;
    for(int i=0; i<nums.size(); ++i){
        if(m.find(nums[i]) == m.end()){
            //the needed num and it's index
            m[target-nums[i]] = i;
        } else {
            ret.push_back(m[nums[i]]);
            ret.push_back(i);
        }
    }
    return ret;
}

int main(){
    vector<int> nums{3,2,4};
    int target = 6;
    auto ret = twoSum_(nums, target);
    for(auto i : ret){
        cout << i << endl;
    }
}
