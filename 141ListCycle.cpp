/*判断一个链表有没有环
 * Solution:双指针问题，slow每次走1步，fast每次走两步，如果可以相遇，那么就有环，否则没有
 * 注意判断是否不小心访问了NULL即可
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *slow(head), *fast(head);
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        } 
        return false;
    }
};
