/* Realize the Inorder visit use O(1) space, and O(n) time
 * MirrosTravel
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(NULL), right(NULL) {}
};

class Tree{
public:
    Tree():root(NULL){}
    Tree(TreeNode* _root): root(_root){}
    void Inorder(TreeNode* root);

private:
    TreeNode* root;
};

void Tree::Inorder(TreeNode* root){
    if(root == NULL)
        return;
    TreeNode* cur = root;
    while(cur){
        if(cur->left){
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur) prev = prev->right;
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                cout << cur->val << " ";
                cur = cur->right;
            }
        } else {
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left        = new TreeNode(2);
    root->right       = new TreeNode(3);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Tree tree(root);
    tree.Inorder(root);
    cout << endl;
}

