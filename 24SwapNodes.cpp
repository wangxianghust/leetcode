#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **prevp = &head;
        ListNode *a;
        ListNode *b;
        //pp(a address pointer to ListNode)
        //pp == a->b->next change to pp == b->a->next and update pp=&(a->next) NOT &next
        while((a = *prevp) && (b = a->next)){
            a->next = b->next;
            b->next = a;
            *prevp = b;
            prevp = &(a->next);
            //NOTICE: the last line is not same as follow 2 lines, cause & is to get address,
            //a->next address is not the new variable m's address.
            //ListNode* m = a->next;
            //prevp = &m;
        }
        return head;
    }
};

void print(ListNode* ret){
    while(ret){
        cout << ret->val << "->";
        ret = ret->next;
    }
    cout << endl;
}

int main(){
    freopen("24test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        Solution Sol;
        int size;
        cin >> size;
        int c;
        cin >> c;
        ListNode *head =  new ListNode(c);
        ListNode **pp = &head;
        for(int j=1; j<size; ++j){
            cin >> c;
            (*pp)->next = new ListNode(c);
            pp = &((*pp)->next); 
        }
        print(head);
        auto ret = Sol.swapPairs(head);
        print(ret);
    }
}
