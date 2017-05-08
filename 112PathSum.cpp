/* 判断二叉树是否有一个路径和是sum
 * 递归判断法，从root到child，每次sum = sum-root->val;
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
    }
};
