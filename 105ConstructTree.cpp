/* 从先序遍历和中序遍历构建二叉树
 * Solution：递归，当一个节点的时候构建root,其他情况分别根据新的中序和前序的序列进行遍历
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_e(preorder.size()), in_e(inorder.size());
        if(pre_e != in_e || pre_e == 0) return NULL;
        return buildTree(preorder, 0, pre_e-1, inorder, 0, in_e-1);       
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int pre_s, int pre_e, vector<int> &inorder, int in_s, int in_e){
        TreeNode* root = new TreeNode(preorder[pre_s]);
        if(pre_s == pre_e){
            return root;
        }
        int i;
        for(i=in_s; i<=in_e; ++i){
            if(inorder[i] == preorder[pre_s])break;
        }    
        int left_len = i - in_s;
        if(left_len > 0){
            root->left = buildTree(preorder, pre_s+1, pre_s+left_len, inorder, in_s, i-1);
        }
        int right_len = in_e - i;
        if(right_len > 0){
            root->right = buildTree(preorder, pre_e-right_len+1, pre_e, inorder, i+1, in_e);
        }
        return root;
    }
};

int main(){
    //AC
}
