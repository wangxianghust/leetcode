/* 将二叉树按照中序遍历的顺序转化为双向链表
 * 对root节点的处理，假设左子树，右子树已经转化为链表，那么下面？
 * root->left = left-subtree right-most node
 * root->right = right-subtree left-most node
 * 但是现在这个方法还是有些问题，OJ过不了，可以convert时候直接转换，不清楚OJ内部咋了
 */

#include <iostream>

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

class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};
 
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root){
        if(root == NULL) return NULL;
        TreeNode* head = convert(root);
        DoublyListNode dum(0);
        DoublyListNode* dummy = &dum;
        while(head){
            DoublyListNode node(head->val);
            dummy->next = &node;
            node.prev = dummy;
            dummy = dummy->next;
            head = head->right;
        }
        dum.next->prev = NULL;
        return dum.next; 
    }

    TreeNode* convert(TreeNode* root) {
        // Write your code here
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;

        TreeNode* left = convert(root->left);

        //get the right most node
        TreeNode* tmp(left);
        while(tmp && tmp->right){
            tmp = tmp->right;
        }
        if(left){
            root->left = tmp;
            tmp->right = root;
        }
        
        TreeNode* right = convert(root->right);
        if(right){
            root->right = right;
            right->left = root;
        }

        return left ? left : root;
    }
};
