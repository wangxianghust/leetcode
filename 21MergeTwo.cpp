/*关于List模拟的题目，时刻注意：
 * 检测是否为空
 * ret = ret->next的迭代不能忘，否则指针不会移动
 * 看看是否需要保留head指针，因为指针在移动
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){} 
};

void print(ListNode* ret);

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0); //a vitural head used for find next element.
        ListNode* ret = head;
        while(l1 != nullptr && l2 != nullptr){
            int val1 = l1->val;
            int val2 = l2->val;
            if(val1 <= val2){
                ret->next =  l1;
                l1 = l1->next;
            } else {
                ret->next = l2;
                l2 = l2->next;
            }
            ret = ret->next;
        }
        if(l1 == nullptr) 
            ret->next = l2;
        else 
            ret->next = l1;
        return head->next;
    }
};

void print(ListNode* ret){
    while(ret){
        cout << ret->val << "-->";
        ret = ret->next;
    }
    cout << endl;
}

int main(){
    freopen("21test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        int size1, size2;
        cin >> size1 >> size2;
        int c;
        cin >> c;
        ListNode *head1 = new ListNode(c);
        ListNode *l1 = head1;
        for(int j=1; j<size1; ++j){
            cin >> c;
            l1->next = new ListNode(c);
            l1 = l1->next;
        }
        
        cin >> c;
        ListNode *head2 = new ListNode(c);
        ListNode *l2 = head2;
        for(int j=1; j<size2; ++j){
            cin >> c;
            l2->next = new ListNode(c);
            l2 = l2->next;
        }

        Solution Sol;
        print(head1);
        print(head2);
        auto head = Sol.mergeTwoLists(head1, head2);
        print(head);
    }
}
