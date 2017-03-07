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
    while(l1){
        l.push_back(l1->val);
        cout << "l1 : " << l1->val << endl;
        l1 = l1->next;
    }
    while(l2){
        r.push_back(l2->val);
        cout << "l2 : " << l2->val << endl;
        l2 = l2->next;
    }

    if(l.size() < r.size()) swap(l, r);
    for(auto i:l)cout << "l " << i << endl;
    for(auto i:r)cout << "r " << i << endl;

	int c = 0;
	for(int i=0; i<r.size(); ++i){
	    int tmp = (l[i] + r[i] + c)%10;
	    c = (l[i] + r[i] + c)/10;
	    ret.push_back(tmp);
	}
	for(int i=r.size(); i<l.size(); ++i){
	    int tmp = (l[i] + c)%10;
	    c = (l[i] + c) / 10;
	    ret.push_back(tmp);     
	}
    if(c==1)ret.push_back(c);

    //reverse(ret.begin(), ret.end());
    
    for(auto i:ret) cout << "vec " << i << endl;
    ListNode *retL = new ListNode(ret[0]); 
    ListNode *root = retL;
    for(int i=1; i<ret.size(); ++i){
        root->next = new ListNode(ret[i]);
        root = root->next;
    }
    //root->next = nullptr;
    return retL;
}

int main(){
    ListNode* l1 = new ListNode(3);
    l1->next = new ListNode(7);
    //l1->next->next = new ListNode(9);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(2);
    
    auto ret = AddTwo(l2, l1);
    while(ret){
        cout << "ret " << ret->val << endl;
        ret = ret->next;
    }
}
