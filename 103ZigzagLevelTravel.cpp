/*Zigzag Order visit the tree
 * just simulation
 * Iteration: Use queue to push the node, and add NULL on the end of every level.
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //This an iteration soluton
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if(root == NULL) return ret;
        vector<int> level;
        deque<TreeNode*> que;
        que.push_back(root);
        bool is_zig = false; //zig is go right
        while(! que.empty()){
            is_zig = !is_zig;
            int size = que.size();
            while(size--){
                if(is_zig){ //this level go right, next level is reverse
                    TreeNode* cur = que.back();
                    que.pop_back();
                    level.push_back(cur->val);
                    if(cur->left) que.push_front(cur->left);
                    if(cur->right) que.push_front(cur->right);
                } else {
                    TreeNode* cur = que.front();
                    que.pop_front();
                    level.push_back(cur->val);
                    if(cur->right) que.push_back(cur->right);
                    if(cur->left) que.push_back(cur->left);
                }
            } 
            ret.push_back(level);
            level.clear();           
        }
        return ret;
    }
};

int main(){
    //AC
}

