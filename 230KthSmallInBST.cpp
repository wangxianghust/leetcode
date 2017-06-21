/*在一个BST中找到第k小的元素
 * Solution：直观的，采用中序遍历
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        return inOrder(root);
    }

    int inOrder(TreeNode* root){
        if(root){
            if(root->left) inOrder(root->left);
            count--;
            if(count == 0) return root->val;
            if(root->right) inOrder(root->right);
        } 
    }
private:
    int count;
};
