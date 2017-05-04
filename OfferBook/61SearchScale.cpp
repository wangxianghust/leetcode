/* 给定排序数组和target,找出target的开始，结束位置
 * 二分搜索的改编版
 */

#include <vector>
using namespace std;

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> ret{-1,-1};
        if(A.size() == 0) return ret;
        int high = A.size()-1;
        int low(0);
        int mid;
        while(high >= low){
            mid = low + (high-low)/2;
            if(A[mid] >= target) high = mid-1; //even if get target, high will go left 1 step.
            else low = mid+1; //so if find, it will low and is the left-most one.
        }
        if(low >= A.size() || A[low] != target) return ret;
        ret[0] = low;

        low = 0;
        high = A.size()-1;
        while(high >= low){
            mid = low +(high-low)/2;
            if(A[mid] > target) high = mid-1;
            else low = mid+1;
        }
        ret[1] = high;
        return ret;
    }
};
