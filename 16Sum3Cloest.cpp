#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int curCloest = INT_MAX;
        int ret = 0;
        for(int i=0; i<size; ++i){
            int target_ = target - nums[i];
            //use two pointer to iter
            int start = i + 1;
            int end = size - 1;
            while(start < end){ //constraints
                int sum = nums[start] + nums[end];
                if(sum > target_) {
                    --end;
                } else if(sum < target_){
                    ++start;
                } else {
                    return target;
                }
                int dif = abs(sum - target_);
                if(dif < curCloest){ //update curCloest and save ret
                    curCloest = dif;
                    ret = sum + nums[i];
                }
            }
        }
        return ret; 
    }
};

int main(){
    freopen("16test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        int target;
        cin >> target;
        int size;
        cin >> size;
        vector<int> nums;
        for(int j=0; j<size; ++j) {
            int c;
            cin >> c;
            nums.push_back(c);
        }
        Solution Sol;
        cout << Sol.threeSumClosest(nums, target) << endl;
    }

}
