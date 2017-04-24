/*Problem: 从先序遍历和中序遍历来构建二叉树
 * Solution: 从先序遍历得到根节点的信息，从中序遍历得到左右子树
 * 递归构建tree
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};

int main(){
    //AC
}
