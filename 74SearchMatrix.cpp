/*问题：给定一个二维数组，从左到右，从上到下是排序好的，求迅速查找一个数的位置
 * 解答：将二维坐标转化为一维连续坐标，经典的二分查找法。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = col*row-1;
        while(low <= high){
            int mid = (high-low)/2 + low;
            int i = mid/col;
            int j = mid - i*col;
            if(matrix[i][j] > target) high = mid-1;
            else low = mid+1;
        } //if exists, return; if not, return the left index of its. so index may be negative.
        if(high<0) return false;
        int i = high/col;
        int j = high - i*col;
        return matrix[i][j] == target;
    }
};
