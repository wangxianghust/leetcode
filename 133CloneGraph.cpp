/* 复制一个无向图
 * Solution：参考二叉树的复制来吧, 注意和二叉树的不同，二叉树的root访问后就是left和right,left和right之间没有连接
 * 也就是不会重复复制，但是graph 构造的节点还会再次出现，所以需要map来去重。
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        if(book.find(node) == book.end()){
            UndirectedGraphNode* _node = new UndirectedGraphNode(node->label);
            book[node] = _node;
            for(auto ele : node->neighbors){
                _node->neighbors.push_back(cloneGraph(ele));
            }
        }
        return book[node];
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> book;
};

int main(){
    //AC
}
