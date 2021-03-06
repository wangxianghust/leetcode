/* 判断一个Tree是不是balanced tree
 * Solution: 采用从底向上的方法，计算每个节点左右子树的高度，一旦发现高度差超过1，return -1，
 * 后面只要检测是否为-1，是的话继续返回-1，不需要向自上向下的方法那样来遍历每个节点计算
 * 这是bottom to up的方法。
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
        return getHeight(root) != -1;        
    }

    int getHeight(TreeNode* root){
    //如果此时的节点balanced，返回height，or 返回 -1
        if(root == NULL) return 0;
        int left = getHeight(root->left);
        if(left == -1) return -1;
        int right = getHeight(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};
