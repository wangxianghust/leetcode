/*Problem: search a target in the rotated array, the element may be duplicate
 * Solution: duplicate is not a problem but, if nums[lefr] == nums[mid] == nums[right],we should notice
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size-1;
        while(low <= high){
            int mid = (high - low)/2 + low; // (high+low)/2 may overstack.
            if(nums[mid] == target) return true;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                --high;
                ++low;
            } else if(nums[mid] >= nums[low]){//the left half is the sorted array.
                if(target >= nums[low] && target < nums[mid]) high = mid - 1; //the target is in the left SORTED array, valid.
                else low = mid + 1;
            } else {
                if(target > nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }                          
        }
        return false;
    }
};

int main(){
    //AC
}
