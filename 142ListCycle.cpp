/*判断一个链表有没有环,如果有找出环的入点
 * Solution:双指针问题，slow每次走1步，fast每次走两步，如果可以相遇，那么就有环，否则没有
 * 找到相遇点之后，可以求出环的长度n
 * 然后再双指针，fast 从head先走n步，此时slow也从head出发，其相遇的节点是入口
 *
 * 还有更简单的，需要证明：假设相遇点是m,则从head和m点两个指针同时走，相遇点是entry
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* tmp = isCycle(head);
        if(tmp == NULL) return NULL;
        int len = getCycleLen(tmp);
        return getStart(head, len);      
    }

private:
    ListNode* isCycle(ListNode* head){
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow(head), *fast(head);
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return fast;
        }
        return NULL;
    }

    int getCycleLen(ListNode* head){
        int ret = 1;
        ListNode* phead(head->next);
        while(head != phead){
            ++ret;
            phead = phead->next;
        }
        return ret;
    }

    ListNode* getStart(ListNode* head, int len){
        ListNode *slow(head), *fast(head);
        while(len--) fast = fast->next;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
