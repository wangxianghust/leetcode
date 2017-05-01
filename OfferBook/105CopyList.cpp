/* 复杂链表的copy,每个节点有一个任意指向的兄弟
 * Solution: 将复制后的节点插入原节点的后面，复制介绍后，再将两个链表分离
 */

#include <iostream>

using namespace std;

  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
 
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        copyNodes(head);
        copySiblingNodes(head);
        return splitLists(head);
    }

private:
    RandomListNode *copyNodes(RandomListNode* head){
        RandomListNode* h_head(head);
        while(head){
            RandomListNode* node = new RandomListNode(head->label);
            node->next = head->next;
            head->next = node;
            head = node->next;
        }
        return h_head;
    }

    RandomListNode *copySiblingNodes(RandomListNode* head){
        RandomListNode* h_head(head);
        while(head){
            if(head->random){
                RandomListNode* random = head->random;
                head->next->random = random->next;
            }
            head = head->next->next;
        }
        return h_head;
    }

    RandomListNode* splitLists(RandomListNode* head){
        if(head == NULL) return head;
        RandomListNode* copy_head = head->next;
        RandomListNode* copy_node(copy_head);
        if(head){ //先将原list走一步，这样当head == NULL 时候，正好复制完毕。
            head->next = copy_head->next;
            head = head->next;
        }
        while(head){
            copy_node->next = head->next;
            copy_node = copy_node->next;
            head->next = copy_node->next;
            head = head->next;
        }
        return copy_head;
    }
};
