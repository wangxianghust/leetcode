/*删除链表的倒数第K个节点
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *h1(dummy), *h2(dummy);
        while(n--){
            h1 = h1->next;
        }
        while(h1->next){
            h1 = h1->next;
            h2 = h2->next;
        }
        h2->next = h2->next->next;
        return dummy->next;
    }
};
