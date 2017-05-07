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

