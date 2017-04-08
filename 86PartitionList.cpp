/*Problem:Given a value x, then use x to partition List, the smaller is 
 * on the left and bigger on the right, the preserve order should be kept.
 *Solution: find first small and large as two head, then go on two lists, the last
 * step is use small->next = large->head;
 */

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

void watch(ListNode* root){
    cout << root->val << endl;
}

class Solution {
public:
    //两种方法思想是一样的，不过上面这种更加简洁。
    ListNode* partition(ListNode* head, int x) {
        ListNode small = ListNode(0);
        ListNode big = ListNode(0);
        ListNode* small_dummy = &small;
        ListNode* big_dummy = &big;
        while(head){
            if(head->val < x){
                small_dummy->next = head;
                small_dummy = small_dummy->next;
            } else {
                big_dummy ->next = head;
                big_dummy = big_dummy->next;
            }
            head = head->next;
        }
        big_dummy->next = NULL;
        small_dummy->next = big.next;
        return small.next; 
    }

    ListNode* partition_(ListNode* head, int x) {
        if(!head || !head->next) return head; 
        ListNode *small(NULL);
        ListNode *big(NULL);
        ListNode* h_head = head;
        if(head->val < x){
            small = head;
            //watch(small);
        } else {
            big = head;
        }
        if(small){
            while(head){//find the first ele that < and >=
                if(head->val < x){
                    head = head->next;
                    continue;
                }
                big = head;
                //watch(big);
                break;
            }
        } else {
            while(head){
                if(head->val >= x){
                    head = head->next;
                    continue;
                }
                small = head;
                break;
            }
        }

        ListNode* small_dummy = new ListNode(0);
        small_dummy->next = small;
        ListNode* big_dummy = new ListNode(0);
        big_dummy->next = big;
        while(h_head){//make two lists : < and >=
            if(h_head->val < x){
                small_dummy->next = h_head;
                small_dummy = small_dummy->next;
            } else {
                big_dummy->next = h_head;
                big_dummy = big_dummy->next;
            }
            h_head = h_head->next;
        }
        big_dummy->next = NULL;
        small_dummy->next = big;//joint two lists
        return small==NULL ? small_dummy->next : small;//small may be NULL, we use small_dummy->next here.
    }
};

void print(ListNode* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main(){
    freopen("86test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        int x; cin >> x;
        int size; cin >> size;
        ListNode* head = new ListNode(0);
        ListNode* h_head = head;
        while(size--){
            int i; cin >> i;
            head->next = new ListNode(i);
            head = head->next;
        }
        auto ret = Sol.partition(h_head->next, x);
        print(ret);
    }
}
