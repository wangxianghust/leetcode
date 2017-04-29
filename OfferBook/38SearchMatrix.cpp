/*给定一个Matrix，搜索某个target出现的次数
 * Solution: 从右上角开始，每次比较可以减少一行或者一列，找到一个元素后，可以跳过该列和该行继续查找
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int count(0), i(0), j(col-1);
        while(i < row && j >= 0){
            if(matrix[i][j] < target){
                ++i; // go down, next row to find;
            } else if(matrix[i][j] > target){
                --j; // go left, next col to find;
            } else {
                ++count; // find, and decrease a row and a col;
                --j;
                ++i;
            }
        }
        return count;
    }
};

