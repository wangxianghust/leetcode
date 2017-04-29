/*合并两个链表
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode dum(0);
        ListNode* dummy  = &dum;
        while(l1 && l2){
            if(l1->val <= l2->val){
                dummy->next = l1;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        if(l1)dummy->next = l1;
        else dummy->next = l2;
        return dum.next;
    }
};
