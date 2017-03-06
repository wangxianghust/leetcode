#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};

ListNode* AddTwo(ListNode* l1, ListNode *l2){
    vector<int> l;
    vector<int> r;
    vector<int> ret;
    ListNode *retL(nullptr);
    while(l1 != nullptr){
        l.push_back(l1->val);
        l1 = l1->next;
    }
    while(l2 != nullptr){
        r.push_back(l2->val);
        l2 = l2->next;
    }
    int l1_size = l.size();
    int l2_size = r.size();

    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    if(l1_size < l2_size) swap(l, r);

        int c = 0;
        for(int i=0; i<l2_size; ++i){
            int tmp = (l[i] + r[i] + c)%10;
            c = (l[i] + r[i])/10;
            ret.push_back(tmp);
        }
        for(int i=l2_size; i<l1_size; ++i){
            int tmp = (l[i] + c)%10;
            c = (l[i] + c) / 10;
            ret.push_back(tmp);
        }
        if(c==1)ret.push_back(c);
        
    for(int i=0; i<ret.size(); ++i){
        ListNode *tmp = new ListNode(ret[i]);
        retL = tmp;
        retL = retL->next;
    }
    return retL;
}

int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);

    ListNode* l1(nullptr);
    l1->next = a;
    l1->next = b;
    ListNode* l2(nullptr);
    l2->next = b;
    l2->next = a;
    
    auto ret = AddTwo(l1, l2);
    while(ret->next != nullptr){
        cout << ret->val << endl;
    }
}
