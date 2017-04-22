/*判断两个二叉树是否是完全一样的
 * Solution: 递归求解即可
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val == q->val){
            if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) return true;
        }
        return false;
    }
};
