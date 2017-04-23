/*Problem: find the max depth of the tree
 * Solution: DFS
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ret = dfs(root, 1);
        return ret;
    }
private:
    int dfs(TreeNode* root, int depth){
        if(root == NULL) return depth;
        int left(0),right(0);
        if(root->left) left = dfs(root->left, depth+1);
        if(root->right) right = dfs(root->right, depth+1);
        return max(max(left, right),depth);
    }
};
