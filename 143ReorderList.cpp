/* 重新排列一个List，如1->2->3->4->5->6 变换为 1->6->2->5->4->3
 * 三个步骤：1.寻找mid,使用mid，使用fast, slow两个指针即可
 * 2. reverse后半段，即变为 1->2->3 6->5->4
 * 3. merge 两个链表即可。
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *p1 = head, *p2 = head->next;
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode *head2 = p1->next;
        p1->next = NULL;

        head2 = reverse(head2);
        merge(head, head2);
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev(NULL);
        ListNode* cur(head);
        ListNode* ret;
        while(cur){
            ret = cur;
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return ret;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head(l1);
        while(l1 && l2){
            ListNode* pl1 = l1->next;
            l1->next = l2;
            ListNode* pl2 = l2->next;
            l2->next = pl1;
            l1 = pl1;
            l2 = pl2;
        }
        return head;
    }
};
