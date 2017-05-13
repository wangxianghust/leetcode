/*后序遍历二叉树，iteration版本
 * Solution:回顾下先序遍历实现：stack, 先push right-children 然后 left-children
 * 先序的顺序是 root-left-right    后序的顺序是 left-right-root
 * 所以先修改先序遍历成为root-right-left, 然后再reverse即可
 * 所谓的修改是：压栈时候，先left,后right。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
    }
};
