/* 给一个BST,可以求出next smallest：意思是下一个最小的点 ，O(1) time and O(h) space.
 * 首先虽然传入的参数是root,但是最小的并不是root，而是most-left.
 * Solution: 模拟,其实是在模拟中序遍历，把几个操作拆分开了。先是一直向左走，然后print root->val，最后压入right subtree.
 */

#include <iostream>
#include <stack>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        goLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty(); 
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = sta.top();
        sta.pop();
        if(top->right) goLeft(top->right);
        return top->val;
    }
private:
    void goLeft(TreeNode* node){
        if(node){
            sta.push(node);
            while(node->left){
                sta.push(node->left);
                node = node->left;
            }   
        }
    }
private:
    stack<TreeNode*> sta;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
