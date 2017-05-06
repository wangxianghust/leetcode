/* 检测链表中是否存在环，然后返回环的起点
 * Solution:1.双指针：slow每次走1step，fast每次走2step，如果fast走到NULL，则无环；否则两个指针必然相较于环内
 * 2.让一个指针走一圈，可以得到环的长度N。
 * 3.再用两个指针在head，指针一先走N steps, 此时两个指针同时出发，相遇的点即为起点。
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        ListNode* node_in_cycle = isCycle(head);
        if(node_in_cycle == NULL) return NULL;
        int cycle_len = getCycleLen(node_in_cycle);
        return getStart(head, cycle_len);
    }

    ListNode* isCycle(ListNode* head){
        ListNode* slow(head), *fast(head);
        if(head == NULL || head->next == NULL) return NULL;
        while(fast->next && slow){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == NULL) return NULL;
            if(slow == fast) return fast;
        }
        return NULL;
    }

    int getCycleLen(ListNode* head){
        ListNode* start(head);
        int len = 1;
        while(start != head->next){
            head = head->next;
            ++len;
        }
        return len;
    }

    ListNode* getStart(ListNode* head, int len){
        ListNode *fast(head), *slow(head);
        while(len--){
            fast = fast->next;
        }
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
