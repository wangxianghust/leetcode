/* 判断一个Tree是不是balanced tree
 * Solution: 采用从底向上的方法，计算每个节点左右子树的高度，一旦发现高度差超过1，return -1，
 * 后面只要检测是否为-1，是的话继续返回-1，不需要向自上向下的方法那样来遍历每个节点计算
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int l_height = getHeight(root->left);
        int r_height = getHeight(root->right);
        return (abs(l_height - r_height) < 2 && isBalanced(root->left) && isBalanced(root->right)) ? 1 : 0;
    }

    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};
