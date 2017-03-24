/*很容易得到遍历两遍的结果，但是Only one pass
 * 时间上有限制，就需要从空间上trade-off.
 * 用t2和t1进行同步遍历
 *
 * NOTICE:List的题目容易出错，这里有一个tricky，ListNode* h_head = new Node(INT_MIN), h_head->next = head
 * 自己添加一个头指针，这样比较容易理解。
 * 注意next next, 一般对node判定null,而不是node->next.
 */
#include <iostream>
#include <climits>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode* h_head = new ListNode(INT_MIN);
        h_head -> next = head;
        ListNode* tmp = h_head;//we have move one step here
        for(int i=0; i<n; ++i){
            tmp = tmp->next;
        }  
        ListNode* t = h_head;
        while(tmp->next != nullptr){ //add a h_head, tmp must not be null.
            t = t->next;
            //if(t->next == nullptr) break;
            tmp = tmp->next; //tmp->next should be deleted. (len-(len-n))
        }
        t->next = t->next->next;
        return h_head->next;
    }
};

void print(ListNode* head){
    while(head != nullptr){
        head = head->next;  //the first one is constructed by myself, skip it.
        if(head)cout << head->val << " ";
    }
    cout << endl;
}

int main(){
    freopen("19test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int n;
        cin >> n;
        int size;
        cin >> size;
        ListNode* head = new ListNode(INT_MIN);
        ListNode* h_head = head;  //save the head pointer.
        for(int i=0; i<size; ++i){
            int d;
            cin >> d;
            head->next = new ListNode(d);
            head = head->next;
        }
        print(h_head);
        print(Sol.removeNthFromEnd(h_head, n));
    }
}
