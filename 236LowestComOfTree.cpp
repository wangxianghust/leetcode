/* give a tree, find the common ancestor of two nodes
 * Solution:现在给的是一个普通的Tree，要找到root到p,q的路径，然后路径的第一个分叉点就是答案
 */

#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
};
