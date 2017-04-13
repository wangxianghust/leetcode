/*Problem: 给定1~n,输出由这n个数组成的BST
 * Solution: 回溯法
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return generate(1,n);
    }
private:
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> tree;
        if(start > end){
            tree.push_back(NULL);
            return tree;
        }
        if(start == end){  //Can get from above
            TreeNode* root = new TreeNode(start);
            tree.push_back(root);
            return tree;
        }

        vector<TreeNode*> left, right;
        for(int i=start; i<=end; ++i){
            left = generate(start, i-1);
            right = generate(i+1, end);

            for(TreeNode* l : left){
                for(TreeNode* r : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right =r;
                    tree.push_back(root);
                }
            }
        }
        return tree;
    }
};

int main(){
    //AC
}
