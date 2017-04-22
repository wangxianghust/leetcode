/* Problem：BST中的两个节点交换位置，求将其复原eg.1 5 16 10 12 15 6 ---> 1 5 6 10 12 15 16
 * Solution：Inorder遍历结果是一种解决方案，使用MirrosTravel 可以达到
 * O(1) space.
 */

#include <iostream>
#include <climits>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
       inOrder(root);
       swap(first->val, second->val); 
    }
public:
    Solution():prev(new TreeNode(INT_MIN)),first(NULL),second(NULL) {}
private:
    void inOrder(TreeNode* root){
        TreeNode* cur = root;
        //TreeNode* _cur(prev); //save the value will be visited current.
        while(cur){
            if(cur->left){
                TreeNode* pre = cur->left;
                while(pre->right && pre->right != cur) pre = pre->right;
                if(pre->right == NULL){
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    if(first == NULL && prev->val > cur->val) first = prev;
                    if(first != NULL && prev->val > cur->val) second = cur;
                    prev = cur;
                    pre->right = NULL;
                    cur = cur->right;
                }
            } else {
                if(first == NULL && prev->val > cur->val) first = prev;
                if(first != NULL && prev->val > cur->val) second = cur;
                prev = cur;
                cur = cur->right;
            }
        }
    }
private:
   //核心思路，中序遍历寻找违法的两个节点，交换其value，不过只是O(n) space 的。 
    void inOrder_(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        if(first == NULL && prev->val > root->val) first = prev;
        if(first != NULL && prev->val > root->val) second = root;
        prev = root;
        inOrder(root->right); 
    }
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
};

int main(){
    
}
