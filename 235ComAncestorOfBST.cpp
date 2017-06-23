/* give a BST, find the common ancestor of two nodes
 * Solution: 从root开始寻找，一旦发现介于两个数之间的即为结果，否则根据大小关系判定
 * 向left还是right走。
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
        if(p->val > q->val) swap(p,q);
        if(root->val >= p->val && root->val <= q->val) return root;

        if(root->val <= p->val) return lowestCommonAncestor(root->right, p, q);
        else return lowestCommonAncestor(root->left, p, q);
    }
};
