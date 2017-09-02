/* 对于tree，只要从上向下，任意的起点和终点，只要和为sum即可，求这样path的数量
 * Solution：1. 设置pre，记录该节点之前的sum
 *           2. 对于一个node，就两种操作，a.选择这个点 b.不选这个点，从left，right子树入手
 *           3. 以上两种可以理解为选择起点，对于选择终点就是判断path sum是否对，或者不对的话继续向下寻找
 */
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        // choose start point.
        return sumUp(root, 0, sum)  // choose this node as start
            + pathSum(root->left, sum) + pathSum(root->right, sum); //NOT choose as start.
    }

private:
    int sumUp(TreeNode* root, int pre, int sum){
        if(root == NULL) return 0;
        int current = pre + root->val;
        return (sum == current) // valid, choose it as end.
            + sumUp(root->left, current, sum) + sumUp(root->right, current, sum); // NOT valid, go left and right to choose path.
    }
};
