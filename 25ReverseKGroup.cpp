/*Problem：给定一个List，每K个为一组将其翻转，如果最后一组不够K个，则不进行翻转
 * Solution：递归，模拟操作，先翻转k个，再继续下一组
 */

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for(int i=0; i<k; ++i){
            if(!node) return head;
            node = node->next;
        }
        ListNode* new_head = reverse(head, node); //node is the (k+1)th ele.
        head->next = reverseKGroup(node, k); //update the the pre group last ele point to new head.
        return new_head;
    }
private:
    ListNode* reverse(ListNode* first, ListNode* last){  
    //the last is the (k+1)th ele, 如 1 2 3 4 5 当k=3, 则 3 2 1 4 5，first = 1, last = 4
        ListNode* prev = last;
        while(first != last){
            ListNode* next_first = first->next;
            first->next = prev; //reverse
            prev = first;
            first = next_first; //first pointer go on
        }
        return prev; //now the first is last
    }
};

int main(){
    //AC
}
