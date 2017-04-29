/*使用两个stack模拟一个queue
 * Solution: push进入stack1, pop 从stack2, 如果stack2为空，将stack1的全部搬运到stack2,继续
 * 也就是stack1 handle push, stack2 handle push and pop.
 */
#include <stack>
#include <exception>

using namespace std;

class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int t = top();
        stack2.pop();
        return t;        
    }

    int top() {
        // write your code here
        if(stack2.empty()){
            while(!stack1.empty()){
                int t = stack1.top();
                stack1.pop();
                stack2.push(t);
            }
        }
        if(!stack2.empty()){
            return stack2.top();
        } else {
            throw exception();
        }
    }
};

