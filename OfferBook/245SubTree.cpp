/*判断一棵树是不是另一颗的子树
 * Solution: 递归判断即可
 * 注意先选择可能的节点，判断是否完全相同的树，如果不是的话，递归寻找T1的左右子树。
 */

#include <iostream>

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
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2){
        if(T2 == NULL) return true; //when T2 is null, null is the subtree of any non-empty tree.
        if(T1 == NULL) return false;
        return DoesT1HasT2(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }

    bool DoesT1HasT2(TreeNode *T1, TreeNode *T2) {
        // is T1 is same as T2, I mean T1 == T2, not include relationship.
        if(T1 == NULL && T2 == NULL) return true;  // so only T1 and T2 is null at same time, T1 is equal T2.
        if(T1 == NULL || T2 == NULL) return false;
        if(T1->val != T2->val) return false;
        return (DoesT1HasT2(T1->left, T2->left) && DoesT1HasT2(T1->right, T2->right));
    }
};
