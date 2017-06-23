/*在一个BST中找到第k小的元素
 * Solution：直观的，采用中序遍历
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
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        ret = 0;
        inOrder(root);
        return ret;
    }

    void inOrder(TreeNode* root){
        if(root){
            if(root->left) inOrder(root->left);
            count--;
            cout << root->val << "--" << count << endl;
            if(count == 0) {ret = root->val; return;}
            if(root->right) inOrder(root->right);
        } 
    }
private:
    int count;
    int ret;
};
