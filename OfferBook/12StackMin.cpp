/*实现一个O(1)时间查询min的stack,其他操作也是O(1)
 * Solution:空间换时间，添加一个辅助栈，和实际栈的大小一一对应，不过保存
 * 的是截止到这个值的min
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        if(sta.empty()){
            sta.push(number);
            sta_min.push(number);
        } else {
            int top = sta_min.top(); //update the min_top;
            if(number < top) sta_min.push(number);
            else sta_min.push(top);
            sta.push(number);
        }
    }

    int pop() {
        // write your code here
        if(!sta.empty()){
            int top = sta.top();
            sta.pop();
            sta_min.pop();
            return top;
        } else {
            return -1;
        }
    }

    int min() {
        // write your code here
        if(!sta.empty()){
            return sta_min.top();
        } else {
            return -1;
        }
    }
private:
    stack<int> sta;
    stack<int> sta_min;
};

