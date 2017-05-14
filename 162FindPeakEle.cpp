/*寻找局部最大值，默认左右两个边界是负无穷大，如果有多个peak,任意返回一个index就可以
 * Solution：e,先确定端点，再找升序序列直到停止再判断
 * 优化：本题可以使用二分查找法，为啥这么说呢？还是和边界有关，因为边界最小啊，每次比较mid和mid+1
 * nums[mid] > nums[mid+1], 则向左，令high = mid，因为mid是安全的。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement_(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[size-1] > nums[size-2]) return size-1;
        int index = 0;
        //there must be a peak, cause nums[-1] = nums[n] = INT_MIN;
        while(index+1 < size && nums[index] < nums[index+1]) ++index;
        return index;
    }

    int findPeakElement(vector<int> &nums){
        int left(0), right(nums.size()-1);
        while(left < right){
            int mid = (right-left)/2 + left;
            int _mid = mid + 1;
            if(nums[mid] > nums[_mid]) right = _mid;
            else left = _mid;
        }
        return left;
    }
};
