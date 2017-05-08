/*将一个二叉树压平，按照先序遍历的序列，压成一条类似链表的结构，使用right指针表示下一个
 * Solution: 因为每次都是先handle left-child, 所以如果有left-child，先处理，or root=root->right
 * 那么如何处理呢？因为要将左子树放在right,因此要把right-child连在左子树中most-right child.
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* now = root;
        while(now){
            if(now->left){
                TreeNode* pre = now->left;
                while(pre->right)pre = pre->right;
                pre->right = now->right;
                now->right = now->left;
                now->left = NULL;   //must make left to be null or the program will not terminate.
            }
            now = now->right;
        }
    }
};
