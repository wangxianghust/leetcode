/*判断一个链表有没有环,如果有找出环的入点
 * Solution:双指针问题，slow每次走1步，fast每次走两步，如果可以相遇，那么就有环，否则没有
 * 找到相遇点之后，可以求出环的长度n
 * 然后再双指针，fast 从head先走n步，此时slow也从head出发，其相遇的节点是入口
 *
 * 还有更简单的，需要证明：假设相遇点是m,则从head和m点两个指针同时走，相遇点是entry
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
    ListNode *detectCycle(ListNode *head) {
        
    }
};
