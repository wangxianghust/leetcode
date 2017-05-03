/* 求两个单链表的第一个交叉点
 * Solution：既然是单链表，一旦两个链表相交，则后面的节点都是相交的
 * 因此，先得到两个链表的长度，dif = long - short, 让long先走dif steps，然后同时走，
 * 得到的第一个相交点就是两个单链表的第一个交点
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        ListNode* long_head = headA;
        ListNode* short_head = headB;
        int dif = lenA - lenB;
        if(dif < 0){
            dif = lenB - lenA;
            long_head = headB;
            short_head = headA;
        }
        while(dif--) long_head = long_head->next;
        for(; long_head && short_head && (long_head != short_head); ){
            long_head = long_head->next;
            short_head = short_head->next;
        }

        return long_head;
    }
private:
    int getLength(ListNode* head){
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
};
