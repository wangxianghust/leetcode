/* 从后序遍历和中序遍历构建二叉树
 * Solution：递归，当一个节点的时候构建root,其他情况分别根据新的中序和后序的序列进行遍历
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_e(postorder.size()), in_e(inorder.size());
        if(post_e != in_e || post_e == 0) return NULL;
        return buildTree(postorder, 0, post_e-1, inorder, 0, in_e-1);       
    }
private:
    TreeNode* buildTree(vector<int>& postorder, int post_s, int post_e, vector<int> &inorder, int in_s, int in_e){
        TreeNode* root = new TreeNode(postorder[post_e]);
        if(post_s == post_e){
            return root;
        }
        int i;
        for(i=in_s; i<=in_e; ++i){
            if(inorder[i] == postorder[post_e])break;
        }    
        int left_len = i - in_s;
        if(left_len > 0){
            root->left = buildTree(postorder, post_s, post_s+left_len-1, inorder, in_s, i-1);
        }
        int right_len = in_e - i;
        if(right_len > 0){
            root->right = buildTree(postorder, post_e-right_len, post_e-1, inorder, i+1, in_e);
        }
        return root;
    }
};

int main(){
    //AC
}

