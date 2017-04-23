/*Level Order visit the tree
 * just simulation
 * Iteration: Use queue to push the node, and add NULL on the end of every level.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        dfs(root, 0, ret);
        return ret;
    }
private:
    void dfs(TreeNode* root, int depth, vector<vector<int>> &ret){
        if(root == NULL) return;
        if(depth >= ret.size()){
            ret.push_back(vector<int>());
        }
        ret[depth].push_back(root->val);
        dfs(root->left, depth+1, ret);
        dfs(root->right, depth+1, ret);
    }
public:
    //This an iteration soluton
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        vector<int> level;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL); //NULL as the end of every level
        while(! que.empty()){
            TreeNode* top = que.front();
            que.pop();
            if(top == NULL){
                //the end of the level
                ret.push_back(level);
                level.clear();
                if(que.size() > 0){
                    que.push(NULL); //add the end flag to this new level
                }
            } else {
                level.push_back(top->val);
                if(top->left) que.push(top->left);
                if(top->right) que.push(top->right);
            }
        }
        return ret;
    }
};

int main(){
    //AC
}
