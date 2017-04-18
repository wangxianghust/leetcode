/* Problem: 判定一个二叉树是不是有效的二叉查找树
 * Solution: 中序遍历，判断是否顺序即可 
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    bool isValidBST(TreeNode* root){
        if(!root) return true;
        InOrder(root);
        for(size_t i=0; i<ret.size()-1; ++i){
            if(ret[i] >= ret[i+1]) return false;
        }
        return true;
    }

private:
    void InOrder(TreeNode* root){
        if(root){
            InOrder(root->left);
            ret.push_back(root->val);
            InOrder(root->right);
        }
    }
private:
    vector<int> ret;


    //wrong
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root){
            if( !root->left || root->left->val < root->val ){
                if(!root->right || root->right->val > root->val){
                    if(isValidBST(root->left) && isValidBST(root->right))return true;
                }
            }
            return false;
        }
    }
};

int main(){
    //AC
}
