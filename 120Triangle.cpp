/*给定一个三角形，求出一条路径，sum最小，要求使用O(n) spaces, which space is the #rows.
 * Solution:DP, bottom to up.每次将下一层的结果迭代到上一层，eg path[i] = triangle[k][i] + min(path[i], path[i+1]), k is now level.
 * return path[0] is ok.
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        if(size < 1) return -1;
        vector<int> path(triangle.back());
        for(int level=size-2; level>=0; --level){
            for(int i=0; i<=level; ++i){
                path[i] = triangle[level][i] + min(path[i+1], path[i]);
            }
        }
        return path[0];
    }
};
