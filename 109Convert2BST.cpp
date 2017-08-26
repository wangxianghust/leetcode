/*给定一个升序的链表，求高度平衡的BST
 * Solution:要求高度平衡，那么每次选择数组中间的元素作为root,剩下两边作为左右子树
 * 遍历即可,本质上在构造中序遍历
 * 重点是先构造左子树，中间处理部分(root = new TreeNode(head->val)，head=head->next), 构造右子树
 * O(1) spaces, O(n) time.
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }

private:
    TreeNode* sortedListToBST(ListNode*head, ListNode*tail){
        if(head == tail){
            return NULL;
        }
        if(head->next == tail){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode* mid=head, *tmp=head;
        while(tmp!=NULL && tmp->next !=NULL){
            tmp = tmp->next->next;
            mid = mid->next;
        }
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tmp);
        return root;
    }
};
