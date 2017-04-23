/*Problme: 判断一个树是不是镜像对称的(注意是对称的，不是相同的)，使用递归和迭代的方法
 *Solution: Recurssive and Iterarion: why iteration use queue, cause if parent is invalid then
 * two tree is not same, just return.
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
//Iteration
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q1, q2;
        TreeNode* l, *r;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            l = q1.front();
            q1.pop();
            r = q2.front();
            q2.pop();
            
            if(l == NULL && r == NULL) continue;
            if(l == NULL || r == NULL) return false;
            if(l->val != r->val) return false;

            q1.push(l->left);
            q1.push(l->right);
            q2.push(r->right);
            q2.push(r->left);
        } 
        return true;
    }       
    
//Recursscive
public:
    bool isSymmetric_(TreeNode* root) {
        if(root == NULL) return true;
        return isEqual(root->left, root->right);
    }
private:
    bool isEqual(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL) return true;
        if(l == NULL || r == NULL) return false;
        if(l->val != r->val) return false;
        if(isEqual(l->left, r->right) && isEqual(l->right, r->left)) return true;
        else return false;
    }
};
