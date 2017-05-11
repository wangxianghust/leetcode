/* 给出一堆XXOO组成的二维矩阵，发现被X包围的O,并将O变成X.
 * 直接的想法是，什么叫被X包围？答，1. O在边界上不会被包围 2. 和未被包围的O相连接的O未被包围。
 * 这里有关键的关系，相连接的是一组，所以想到使用并查集，把边界的O和X放在一个集合叫做Union，相连接的O放在一起
 * 最后遍历，发现没有和X连接的，都是未被包围的节点。
 */

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
    }
};
