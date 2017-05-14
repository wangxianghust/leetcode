/*求两个List的交点，没有则返回NULL
 * Solution：先求出两个链表的长度，然后让Long list go (long-short)steps first, then go together, the first intersection is answer.
 * 2.也可以不用diff,直接让两个链表cur1, cur2走，一旦走完A,就从B再走,第一个相遇点就是答案，最多走O(m+n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    }
};
