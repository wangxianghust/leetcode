/* 打印出二叉树的所有路径
 * Solution：回溯法
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root == NULL) return ret;
        findPaths(root, "", ret);
        return ret;       
    }

private:
    void findPaths(TreeNode* root, string path, vector<string> &paths){
        if(root->left == NULL && root->right == NULL){
            path += to_string(root->val);
            paths.push_back(path);
        } else {
            if(root->left) findPaths(root->left, path+to_string(root->val)+"->", paths);
            if(root->right) findPaths(root->right, path+to_string(root->val)+"->", paths);
        }
    }
};

int main(){
    //AC
}
