### ***BackTracking***
---
https://www.cis.upenn.edu/~matuszek/cit594-2012/Pages/backtracking.html
**概念**
回溯在tree,graph上的实现是DFS，回溯可以使用递归实现（当然用stack）模拟生成也是可以的。

**一般形式**
```cpp
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
`` `

Some interesting founds:
--
stack algorithm terminates successfully, the nodes on stack form the path(reverse order) from root to goal leaf.

How to make codes clean
---
- function isLeaf to decide the leaf
- list all children, if the children have the ORDER is best.convience for determining the next try.
    上面在具体问题中并不直观，需要找到合理的遍历子节点的方式
- use isSafe() funtion to cut some children when choose next child.

***DUBUG***
---
学会使用缩进，同时使用specialized print function. eg
```cpp
const bool debugging = false;
void Enter(node){
    if(debugging){
        print node;
        indent = indent + "| ";
    }
}
```

Template
------
https://segmentfault.com/a/1190000006121957
关于回溯问题，有三种问题
- 返回值是true or false(如上的形式)
- 求个数/所有解的信息 --> 设置全局变量，返回值是void
- 设全局best，返回值是void
```cpp
// Get counter or results
void solve(Node n){
    if (n == leaf){
        if(n is a goal){
            ++count;
            //result.push_back(n);
        } else return;
    } else {
        for each child c of n{
            solve(c);
        }
    }
}

//Get best
void solve(Node n){
    if(n == leaf){
        if(n is a goal){
            UPDATE best;
            return;
        } else return;
    } else {
        for each child c of n{
            solve(c);
        }
    }
}

```
