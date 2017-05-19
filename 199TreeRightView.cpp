/* 给定一个二叉树，你站在树的右边，求你能看到的node
 * Solution： 1.模拟题，用cur从root开始，先检查是否有right，有则向右，没有检查左孩子
 * 有向左，没有结束（不对）
 * 2. 使用层序遍历，去每层的最后一个元素即可
 * 3. dfs,设置一个level变量，当level大于当前层数才可以加入。
 */

#include <iostream>
#include <vector>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int> &ret){
        if(root == NULL) return;
        if(level > ret.size()) ret.push_back(root->val);
        dfs(root->right, level+1, ret);
        dfs(root->left, level+1, ret);
    }

    vector<int> rightSideView(TreeNode* root){
        vector<int> ret;
        //int level = 0;
        dfs(root, 1, ret);
    }
    //有问题的解法
    vector<int> rightSideView(TreeNode* root) {
        TreeNode* cur(root);
        vector<int> ret;
        while(cur){
            if(cur->right){
                ret.push_back(cur->right->val);
                cur = cur->left;
            } else {
                cur = cur->left;
            }
        }
    }
};
