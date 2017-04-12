/*Problem: Binary Tree Inorder Travel
 * Solution: recursive and iteration.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ret;
        stack<TreeNode*> sta;
        TreeNode* cur = root;
        while(cur || !sta.empty()){
            if(cur){
                sta.push(cur);
                cur = cur->left;
            } else {
                TreeNode* top = sta.top();
                ret.push_back(top->val);
                sta.pop();
                cur = top->right;
            }
        }
        return ret;
    }
    
public:
    vector<int> inorderTraversal_(TreeNode* root) {
        vector<int> ret;
        inorderRec(root, ret);
        return ret; 
    }
private:
    void inorderRec(TreeNode* root, vector<int> &ret){
        if(root){
            inorderRec(root->left, ret);
            ret.push_back(root->val);
            inorderRec(root->right, ret);
        }
    }
};
