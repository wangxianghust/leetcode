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
        for(int i=1, j=1; i<size && j<size; ){
            if(now == nums[i]){ //the second duplicate is valid;
                nums[j] = nums[i];
                ++i;
                ++j;
                ++ret;
            }
            while(i<size && now == nums[i]) ++i;//find next valid index;
            if(i == size)break;
            now = nums[i];      
            nums[j] = nums[i];
            ++j;
            ++i;
            ++ret;
        }     
        return ret;
    }
};

void print(vector<int> nums){
    for(auto i:nums) cout << i << "--";
    cout << endl;
}

int main(){
    freopen("80test.txt", "r", stdin);
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
