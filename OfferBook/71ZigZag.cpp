/* ZigZag层次遍历一个二叉树
 * Solution: 模拟题，方法还是蛮多的
 * 1.使用两个stack保存，对于奇数层，先push left-child再right-child 到stack[cur],对于偶数层
 * 先push right then left 到stack[next].
 * 2.直接进行常规的层次遍历，再翻转偶数层。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > ret;
        vector<int> level;
        if(root == NULL) return ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            while(size--){
                TreeNode* front = que.front();
                que.pop();
                level.push_back(front->val);
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }
            ret.push_back(level);
            level.clear();
        }
        for(int i=0; i<ret.size(); ++i){
            if(i & 0x1) reverse(ret[i].begin(), ret[i].end());
        } 
        return ret;
    }
};
