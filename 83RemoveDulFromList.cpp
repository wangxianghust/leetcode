/*problem: Delete duplicate from the sorted list
 * Solution: just like before.这样的题目用手画画链表，注意考虑开始情况(一般直接return)，最后一个元素即可。
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* ret = head;
        while(head && head->next){
            //if(head->next == NULL) break;
            if(head->val == head->next->val){
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return ret;
    }
};

int main(){
    //AC
}
