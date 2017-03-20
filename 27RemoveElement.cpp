#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0; 
        int size = nums.size();
        for(int i=0; i<size; ++i){
            if(nums[i] == val) ++count;
            else nums[i-count] = nums[i];
        }
        return size-count;
    }
};

void print(vector<int> nums){
    for(auto i:nums) cout << i << "--";
    cout << endl;
}

int main(){
    freopen("27test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int val;
        cin >> val;
        int size;
        cin >> size;
        vector<int> nums;
        int c;
        for(int j=0; j<size; ++j){
            cin >> c;
            nums.push_back(c);
        }
        cout << Sol.removeElement(nums, val) << endl;
        print(nums);
    }
}

