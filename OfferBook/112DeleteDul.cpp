/* 删除排序链表中的重复元素
 * Solution: dummy head and find duplicate and delete it.
 */

#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};
 
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dum(0);
        ListNode* dummy = &dum;
        dummy->next = head;
        ListNode* prev(dummy);
        ListNode* cur(head);
        while(cur){
            if(cur->next && cur->val == cur->next->val){
                while(cur->next && cur->val == cur->next->val) cur = cur->next;
                prev->next = cur; //link next node.
            } else {
                prev = cur;
                cur = cur->next;
            } 
        }        
        return dum.next;
    }
};
