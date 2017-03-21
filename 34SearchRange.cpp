/*题目意思：一个sorted数组，查找target的range
 *solutions是对二分查找进行修改，先求left，再求right
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1, -1};
        if(nums.size() < 1) return ret;
        int size = nums.size();
        int low = 0;
        int high = size-1;
        while(low <= high){ //YES->left-most   NO->the next right
            int mid = (high-low)/2 + low;
            if(nums[mid] >= target) high = mid-1;
            else low = mid+1;
        }
        //cout << "low " << low << endl;
        if(low > size-1 || nums[low] != target) return ret; //NOT FOUND
        ret[0] = low;
        //To find right bound; 
        low = 0;
        high = size-1;
        while(low <= high){
            int mid = (high-low)/2 + low;
            if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        //cout << "high-- " << high << endl;
        ret[1] = high;
        return ret;
    }
};

template<class T>
void print(vector<T> nums){
    for(auto i : nums) cout << i << " ";
    cout << endl;
}

int main(){
    freopen("34test.txt", "r", stdin);
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
        auto ret = Sol.searchRange(nums, target);
        print(ret);
    }
}



