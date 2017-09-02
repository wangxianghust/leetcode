/*在二叉树上寻找和为sum的路径
 * 回溯法，注意寻找时候需要两个条件，一是sum满足，二是到达了叶子节点
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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
       if(root == NULL) return paths;
       vector<int> path;
       pathSum(root, sum, path);
       return paths; 
    }

public:
    void pathSum(TreeNode* root, int sum, vector<int> path){
        if(root->left == NULL && root->right == NULL && sum == root->val){
            path.push_back(root->val);
            paths.push_back(path);
        }
        path.push_back(root->val);
        if(root->left) pathSum(root->left, sum - root->val, path);
        if(root->right) pathSum(root->right, sum - root->val, path);
        //path.pop_back();
    }

private:
    vector<vector<int>> paths;
};
