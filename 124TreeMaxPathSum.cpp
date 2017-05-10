/* 给定二叉树，求最大路径和，此路径表示的是只要是父子关系即可当做路径，不含方向
 * Solution: 最大路径，所以需要一个max_sum来维护最大值，
 * 什么东西可以影响到max_sum的更新？left_sum + root->val + right_sum.
 * 那么上面的left,right是什么？对于一棵树，我们不选择left,root，right这条路径，而是max(left,right) + root->val
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int maxPathSum(TreeNode* root) {
       int max_sum(INT_MIN); 
       maxPathSum(root, max_sum);
       return max_sum;
    }
private:
    int maxPathSum(TreeNode* root, int &max_sum){
        if(root == NULL) return 0;
        int left = max(0, maxPathSum(root->left, max_sum));
        int right = max(0, maxPathSum(root->right, max_sum));
        if(left+right+root->val > max_sum) max_sum = left + right + root->val;
        return root->val + max(left, right);
    }
};
