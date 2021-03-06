/* 二叉树上每个节点代表一个数字，从root到leaf代表一个数字，求所有能组成的数字和
 * Solution：先序遍历，if(root is leaf)return ret = ret*10 + root->val;
 * else return sum(root->left, ret*10+val) + sum(root->right, ret*10+val)
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
       if(root == NULL) return 0;
       return sumNumbers(root, 0); 
    }

    int sumNumbers(TreeNode* root, int sum){
        if(root->left == NULL && root->right == NULL){
            return sum*10 + root->val;
        }
        
        int val = 0;
        if(root->left != NULL) val += sumNumbers(root->left, sum*10 + root->val);
        if(root->right != NULL)  val += sumNumbers(root->right, sum*10 + root->val);
        
        return val; 
    }
};
