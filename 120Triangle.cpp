/*给定一个三角形，求出一条路径，sum最小，要求使用O(n) spaces, which space is the #rows.
 * Solution:DP, bottom to up.每次将下一层的结果迭代到上一层，eg path[i] = triangle[k][i] + min(path[i], path[i+1]), k is now level.
 * return path[0] is ok.
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
    }
};
