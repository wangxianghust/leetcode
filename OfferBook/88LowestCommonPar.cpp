/*给定二叉树，找到两个节点的公共祖先节点
 * Solution: 先从root找到到达节点的path,再从root出发，求两个单链表开始分开的点就是
 * lowest common parent
 */

#include <iostream>
#include <vector>

using namespace std;

  class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
  }
 
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        vector<TreeNode*> A_set, B_set;
        pathSet(root, A, A_set);
        pathSet(root, B, B_set);
        int i=0;
        while(i<A_set.size() && i<B_set.size() && A_set[i] == B_set[i]) ++i;
        if(i == A_set.size()) return A_set.back();
        if(i == B_set.size()) return B_set.back();
        return A_set[i-1];
    }
private:
    void pathSet(TreeNode* root, TreeNode* to_find, vector<TreeNode*> &path){
        if(root == NULL) return;
        if(root == to_find){
            path.push_back(root);
            return;
        }
        path.push_back(root);
        if(root->left) pathSet(root->left, to_find, path);
        if(root->right) pathSet(root->right, to_find, path);
        path.pop_back();
    }

    //why follow is ok, but top is not.

    bool pathSet(TreeNode* root, TreeNode* to_find, vector<TreeNode*> &path){
        if(root == NULL) return false;
        if(root == to_find){
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if(pathSet(root->left, to_find, path)) return true;
        if(pathSet(root->right, to_find, path)) return true;
        path.pop_back();
        return false;
    }
}; 
