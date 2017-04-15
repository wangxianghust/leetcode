/*Problem: reverse a link from the pos m to pos n. In place and one pass
 * Solution: Simulation.
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode*  next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev(dummy), *cur(head), *ptr_before_m(dummy);
        int index = 0;
        while(cur){
            ++index;
            if(index == m){
                ptr_before_m = prev;
            } else if(index > m && index < n){
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
                continue;
            } else if(index == n){
                ptr_before_m->next->next = cur->next;
                ptr_before_m->next = cur;
                cur->next = prev;
                break;
            }
            prev = cur;
            cur = cur->next;

        }
        return dummy->next;
    }
};

int main(){
//AC
}
