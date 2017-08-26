/*Max subarray
 * Solution: Divide and conquter.
 */
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray_(vector<int> & nums){
        int size = nums.size();
        int ret = INT_MIN;
        int sum_tmp = 0;
        for(int i=0; i<size; ++i){
            sum_tmp += nums[i];
            ret = max(ret, sum_tmp);
            if(sum_tmp < 0) sum_tmp = 0;
        }
        return ret;
    }

    int maxSubArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int ret = maxSubArray(nums, low, high);
        return ret;
    }

private:
    int maxSubArray(vector<int>& nums, int low, int high){
        if(low == high) return nums[low];
        int mid = (high-low)/2 + low;
        int left = maxSubArray(nums, low, mid);
        int right = maxSubArray(nums, mid+1, high);
        int cro = cross(nums, low, mid, high);
        
        int m = max(left, right);
        return max(m, cro);
    }
    int cross(vector<int>& nums, int low, int mid, int high){
        int left_sum = INT_MIN;
        int sum = 0;
        for(int i=mid; i>=low; --i){
            sum += nums[i];
            if(sum > left_sum)left_sum = sum;
        }

        sum = 0;
        int right_sum = INT_MIN;
        for(int i=mid+1; i<=high; ++i){
            sum += nums[i];
            if(sum > right_sum)right_sum = sum;
        }
        return left_sum + right_sum;
    }
};

int main(){
    freopen("53test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<int> nums;
        for(int j=0; j<size; ++j){
            int c; cin >> c;
            nums.push_back(c);
        }

        int ret = Sol.maxSubArray(nums);
        cout << ret << endl;
    }
}
