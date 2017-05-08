/*假设二叉树的每个节点有next指针，指向其同一层的右边，给一个任意的二叉树，求这种操作后的二叉树
 * Solution: 使用now表示当前指针，head,tail(初始化为NULL)表示下一层的起始节点和结束节点。
 * 每当now遍历完该层节点后，head和tail重新赋值处理。
 * 也就是模拟指针操作
 */
#include <iostream>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* now(root), *head(NULL), *tail(NULL);
        while(now){
            if(now->left){
                if(!tail)head = tail = now->left; //this is the start of new level;
                else tail = tail->next = now->left;
            }
            if(now->right){
                if(!tail)head = tail = now->right;
                else tail = tail->next = now->right;
            }
            if((now=now->next) == NULL){ //now level is over
                now = head;
                head = tail = NULL;
            }
        }
    }
};
