/*层次遍历二叉树
 * Solution: 直接使用queue就可以实现，此处可以将每层单独取出打印
 */

#include <iostream>
#include <vector>
#include <queue>

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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > ret;
        vector<int> level;
        queue<TreeNode*> que;
        if(root == NULL) return ret;
        que.push(root);
        while(! que.empty()){
            int size = que.size();
            while(size--){
                TreeNode* front = que.front();
                que.pop();
                level.push_back(front->val);
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }
            ret.push_back(level);
            level.clear();
        }
        return ret;
    }
};
