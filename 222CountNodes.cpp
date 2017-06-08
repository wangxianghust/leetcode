/* 给定一个complete tree，定义是除去最后一层外，其他每层都是都是满的
 * Solution:先判断left,right tree哪个是full tree(一定有一个)，然后直接计算返回答案
 * 如果不是，迭代 1+count(left) + count(right)
 * 如何判断是否是full tree，通过left-most 和 right-most 大小，一样的则是full tree。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        
    }
};
