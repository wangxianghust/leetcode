/*假设二叉树的每个节点有next指针，指向其同一层的右边，给一个满二叉树，求这种操作后的二叉树
 * Solution: 每次从左孩子开始，node->left->next = node->right, if(cur->next)cur->right->next = cur->next->left
 * 也就是模拟指针操作
 */

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
    }
};
