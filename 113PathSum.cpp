/*在二叉树上寻找和为sum的路径
 * 回溯法，注意寻找时候需要两个条件，一是sum满足，二是到达了叶子节点
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
    }
};
