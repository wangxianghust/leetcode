/* Post visit a tree
 * Solution: use non-recursive to realize
 * 非递归的实现方法略复杂：先左子树后右子树，然后根节点，用stack,每次先push right再left,这样pop的时候
 * 可以满足先left后right, 那如何保证root节点在left和right之后访问，答：1.root->left,right均为NULL, 2.设置prev为上一次
 * 访问的节点，如果pre = top->left or top->right,说明已经访问了两个孩子节点，这时候也可以访问root.
 */

#include <iostream>
#include <vector>
#include <stack>

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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> ret;
        if(root == NULL) return ret;
        stack<TreeNode*> sta;
        TreeNode* cur = root;
        sta.push(cur);
        TreeNode* pre(NULL);
        while(!sta.empty()){
            TreeNode* cur = sta.top();
            if( (cur->left == NULL && cur->right == NULL) ||
                ( (pre != NULL) && (pre == cur->left || pre == cur->right) ) ){
                //cur have no children OR children all be visited.
                ret.push_back(cur->val);
                sta.pop();
                pre = cur;
            } else {
                if(cur->right) sta.push(cur->right);
                if(cur->left) sta.push(cur->left);
            }
        }
        return ret;
    }
};
