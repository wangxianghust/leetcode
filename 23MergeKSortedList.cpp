/*Problem: merge k sorted linked lists and return it as one sorted list
 * Solution: 模拟
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* ret = lists[0];
        int size = lists.size();
        for(int i=1; i<size; ++i){
            ret = merge2(ret, lists[i]);
        }
        return ret;
    }
private:
    ListNode* merge2(ListNode* l1, ListNode* l2){
        ListNode dum(0);
        ListNode* dummy = &dum;
        while(l1 && l2){
            if(l1->val > l2->val){
                dummy->next = l2;
                l2 = l2->next;
            } else {
                dummy->next = l1;
                l1 = l1->next;
            }
            dummy = dummy->next;
        }
        if(l1 == NULL){
            dummy->next = l2;
        } else {
            dummy->next = l1;
        }
        return dum.next;
    }
};

int main(){
    //AC
}
