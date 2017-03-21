#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size(); 
        int pos = 0;
        while(pos < size && nums[pos] < target) ++pos;
        return pos;
    }
};

template<class T>
void print(vector<T> nums){
    for(auto i : nums) cout << i << " ";
    cout << endl;
}

int main(){
    freopen("35test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int target;
        int size;
        vector<int> nums;
        cin >> target;
        cin >> size;
        for(int j=0; j<size; ++j){
            int c;
            cin >> c;
            nums.push_back(c);
        }
        print(nums);
        auto ret = Sol.searchInsert(nums, target);
        cout << ret << endl;
    }
}




