/* 深度克隆一个二叉树，也就是克隆一个二叉树
 */

#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        if(root == NULL) return root;
        TreeNode* new_root = new TreeNode(root->val);
        new_root->left = cloneTree(root->left);
        new_root->right = cloneTree(root->right);
        return new_root;
    }
};
