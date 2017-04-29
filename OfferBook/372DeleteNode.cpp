/* 给指向节点的指针，使用O(1)的时间删除节点
 * Solution: 既然给了指针，常规的方法是从头遍历一遍，找到prev,再删除，
 * 但是此处可以将node->next->val赋值给node,再删除node->next
 * 故此时要注意是不是尾节点
 */
#include <iostream>
using namespace std;

  class ListNode {
  public:
      int val;
      ListNode *next;
      ListNode(int val) {
          this->val = val;
          this->next = NULL;
      }
  };
 
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if(!node) return;
        if(node->next != NULL){
            int val = node->next->val;
            node->val = val;
            ListNode* next = node->next->next;
            delete node->next;
            node->next = next;
        } 
    }
};
