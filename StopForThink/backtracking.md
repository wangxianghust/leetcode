### BackTracking
***
http://algorithms.tutorialhorizon.com/introduction-to-backtracking-programming/

**概念**
回溯在tree,graph上的实现是DFS，回溯可以使用递归实现（当然用stack）模拟生成也是可以的。

**一般形式**
int main(){ solve(root) }
bool solve{
    if n is a leaf node{
        if(leaf is a goal)return ture; //如果我们之前每次选择child的时候都是valid的，此时到达leaf就是可行解
        else return false;
    }
    for each child c of n{  //此处：1.遍历所有的children，2.剪枝：invalid的child直接不迭代
        if(solve(c)) return true;
    }    
    return false;
}

STACK version
bool solve(Node n){
    put n on the stack sta;
    while(!sta.empty()){
        if(sta.top == leaf){
            if(leaf is a goal) return true;
            else sta.pop();
        } else {
            if(sta.top() has UNTRIED children c){
                sta.push(c);
            } else sta.pop();
        }
    }
    return false;
}

*Some interesting founds:*
stack algorithm terminates successfully, the nodes on stack form the path(reverse order) from root to goal leaf.

**How to make codes clean**
*1* function isLeaf to decide the leaf
*2* list all children, if the children have the ORDER is best.convience for determining the next try.
    上面在具体问题中并不直观，需要找到合理的遍历子节点的方式
*3* use isSafe() funtion to cut some children when choose next child.

***DUBUG***
学会使用缩进，同时使用specialized print function. eg
const bool debugging = false;
void Enter(node){
    if(debugging){
        print node;
        indent = indent + "| ";
    }
}
