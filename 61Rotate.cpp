/**问题：List操作，rotate the list to the right by k places
 * 方法：正常的链表操作，考虑k>len的情况，移动的是位置是 len-k%len
*/

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k){
        if(!head || head->next == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        int len = 0;
        while(fast->next){
            fast = fast->next;
            ++len;
        }

        for(int i=0; i<len-k%len; ++i){
            slow = slow->next;
        }

        //if(!slow->next) return head;
        
        fast->next = dummy->next; //if slow/fast is the last one, there construct a circle.
        dummy->next = slow->next;
        slow->next = NULL;
        return dummy->next;
    }

    ListNode* rotateRight_(ListNode* head, int k) { //have some problems such as k>len
       if(!head)return head; //border
       ListNode* hhead = new ListNode(0); 
       hhead->next = head;
       ListNode* fast = hhead;
       ListNode* slow = hhead;
       for(int i=0; i<k+1; ++i){ //We use k+1 here, step one more, then we can test fast NOT fast->next;
           fast = fast->next;
       }
       ListNode* end;
       while(fast){
           end = fast;
           fast = fast->next;
           slow = slow->next;
       }
        
       if(!end) return hhead->next;  //the k is the list length, so just return;
       end->next = hhead->next;
       hhead->next = slow->next;
       slow->next = NULL;
       return hhead->next;
    }
};

int main(){
    //AC
}
