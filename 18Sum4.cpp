#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if(size < 4) return vector<vector<int>>();
        vector<vector<int>> ret;
        for(int i=0; i<size-3; ++i){
            int selected_i = nums[i];
            for(int j=i+1; j<size-2; ++j){
                int selected_j = nums[j];
                int start = j+1;
                int end = size-1;
                int target_ = target - nums[i] - nums[j];
                while(start < end){
                    int sum = nums[start] + nums[end];
                    if(sum > target_){
                        --end;
                    } else if(sum < target_){
                        ++start;
                    } else {
                        vector<int> four;
                        four.push_back(nums[i]);
                        four.push_back(nums[j]);
                        four.push_back(nums[start]);
                        four.push_back(nums[end]);
                        ret.push_back(four);
                        while(start < end && nums[start] == four[2]) ++start;
                        while(start < end && nums[end] == four[3]) --end;
                    }
                }
                while(j+1<size-2 && nums[j+1] == selected_j) ++j;//if next is same as now, pointer j move right.
            }
            while(i+1<size-3 && nums[i+1] == selected_i) ++i;
        }
        return ret;
    }
};

void print(vector<vector<int> > ret){
    cout << "Test Case " << endl;
    for(auto i : ret){
        for(auto j : i) cout << j << "--- ";
        cout << endl;
    }
}

int main(){
    freopen("18test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        int target;
        cin >> target;
        int size;
        cin >> size;
        vector<int> nums;
        for(int j=0; j<size; ++j){
            int c;
            cin >> c;
            nums.push_back(c);
        }
        Solution Sol;
        print(Sol.fourSum(nums,target));
    }
}
