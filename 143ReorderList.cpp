/* 重新排列一个List，如1->2->3->4->5->6 变换为 1->6->2->5->4->3
 * 三个步骤：1.寻找mid,使用mid，使用fast, slow两个指针即可
 * 2. reverse后半段，即变为 1->2->3 6->5->4
 * 3. merge 两个链表即可。
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
    void reorderList(ListNode* head) {
        
    }
};
