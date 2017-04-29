/* 使用前序遍历和中序遍历构造二叉树
 * Solution: 根据两种遍历的特点，先寻找root,再寻找left，right tree,递归构造
 * 递归的重点是，向递归函数传递什么参数，答：构造子树需要的preorder 和 inorder数组。
 */

#include <iostream>
#include <vector>
#include <string>
#include <exception>

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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;
        return construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    //pre_s is the start index of preorder.
    TreeNode* construct(vector<int> &preorder, int pre_s, int pre_e, vector<int> &inorder, int in_s, int in_e){
        //construct root
        TreeNode* root = new TreeNode(preorder[pre_s]);
        if(pre_s == pre_e){
            if(in_s == in_e){
                return root;
            } else {
                throw exception();
            }
        } 

        //find the root in the inorder
        int in_root = 0;
        for( ; in_root<inorder.size(); ++in_root) if(inorder[in_root] == preorder[pre_s]) break;
        if(in_root == inorder.size()) throw exception();
        
        //construct left tree, the left tree len should bigger than 0
        int left_len = in_root - in_s;
        if(left_len > 0){
            root->left = construct(preorder, pre_s+1, pre_s+left_len, inorder, in_s, in_root-1);
        }
        int right_len = in_e - in_root;
        if(right_len > 0){
            root->right = construct(preorder, pre_e-right_len+1, pre_e, inorder, in_root+1, in_e);
        }
        return root;
    }
};

void InOrder(TreeNode* root){
    if(root){
        InOrder(root->left);
        cout << root->val << " ";
        InOrder(root->right);
    }
}

int main(){
    vector<int> in{1,2,3,4,5,6,7,8};
    vector<int> pre{5,2,1,3,4,7,6,8};
    Solution Sol;
    TreeNode* root = Sol.buildTree(pre, in);
    InOrder(root);
}
