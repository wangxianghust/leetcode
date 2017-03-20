#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums){
        int size = nums.size();
        if(size == 0) return 0;
        int now = nums[0];
        int ret = 1;
        //i is the nums iter, the next non-duplicate,
        //j is the suitable index to swap.
        for(int i=1, j=1; i<size && j<size; ++i){
            if(now == nums[i]){
                while(i < size && now == nums[i]) ++i;
                if(i == size) break;
            }
            now = nums[i];
            ++ret;
            //swap(nums[i], nums[j]);
            nums[j] = nums[i];
            ++j;
        }
        return ret;
    }

    //this methos only static the numbers of non-duplicate
    int removeDuplicates_(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        int now = nums[0];
        int ret = 1;
        for(int i=1; i<size; ++i){
            if(now == nums[i]){
                continue;
            } else {
                now = nums[i];
                ++ret;
            }
        }
        return ret;
    }
};

void print(vector<int> nums){
    for(auto i:nums) cout << i << "--";
    cout << endl;
}

int main(){
    freopen("26test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size;
        cin >> size;
        vector<int> nums;
        int c;
        for(int j=0; j<size; ++j){
            cin >> c;
            nums.push_back(c);
        }
        cout << Sol.removeDuplicates(nums) << endl;
        print(nums);
    }
}
