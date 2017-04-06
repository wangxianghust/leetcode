/*problem: Delete duplicate from the sorted list,一旦重复，重复的元素就不要了。
 * Solution: just like before.这样的题目用手画画链表，注意考虑开始情况(一般直接return)，
 * 最后一个元素即可。
 * 使用slow和fast双指针，slow用来表示下一个可能的位置，fast表示遍历指针。重要的是slow，我们每次
 * slow->next = fast->next, 然后继续移动fast(head)，检测slow->next是否合法。
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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        while(head){
            while((head->next) && head->val == head->next->val){
                head = head->next;
            }
            if(slow->next == head){ //the while is not run, no duplicate.
                slow = slow->next; //get one more valid ele
            } else {  //Duplicate
                slow->next = head->next; //head->next may be valid,wait while to test.
            }
            head = head->next;
        }
        return dummy->next;
    }
};

int main(){
    //AC
}

