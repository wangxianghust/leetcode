/* 复杂链表的拷贝，每个node除了next指针，还有一个random指针指向另外一个节点
 * Solution: 剑指offer原题，三步：1.按照next进行new&copy，重点是把拷贝后的node放在原来node后面
 * 2.根据步骤一，即使对于复杂链表，也可以迅速找到random node 3.根据奇偶性将原始和拷贝的节点分开。
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
    }
};
