/*给定一个二叉树和target，求出所有和为target的路径和
 * 没办法用穷举所有的path，使用回溯加剪枝的方法
 */

#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};
 
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> paths;
        if(root == NULL) return paths;
        vector<int> path;
        int sum = 0;
        solve(root, target, sum, path, paths);
        return paths;
    }

    void solve(TreeNode* root, int target, int sum, vector<int> path, vector<vector<int>> &paths){
        bool is_leaf = (root->left == NULL) && (root->right == NULL); 
        int val = root->val;
        sum += val;
        path.push_back(val); 
        if(sum == target && is_leaf){
            paths.push_back(path);
            return;
        }
        if(root->left) solve(root->left, target, sum, path, paths);
        if(root->right) solve(root->right, target, sum, path, paths);

        //sum -= val;
        //path.pop_back();
    }
};
