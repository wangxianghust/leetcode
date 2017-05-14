/*一个已经排序的rotated, eg  3 4 5 0 1 2 ，求最小值,含有重复的元素如  3 1 3 3 3 or 3 3 3 1 3，最小值1可能在mid的或者右
 * Solution: 经典二分查找法，在遇到 nums[mid] == nums[left] == nums[right]时候，每次只能减少一个距离，而不是一半(线性)
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        
    }
};
