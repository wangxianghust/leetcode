/* 实现Reverse Polish Notation
 * Solution: stack 模拟题
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        int size = tokens.size();
        for(int i=0; i<size; ++i){
            string now = tokens[i];
            if(now == "+"){
                int top = sta.top();
                sta.pop();
                int second = sta.top();
                sta.pop();
                int tmp = top + second;
                sta.push(tmp);
            } else if( now == "-" ){
                int top = sta.top();
                sta.pop();
                int second = sta.top();
                sta.pop();
                int tmp = second - top;
                sta.push(tmp);
            } else if(now == "*"){
                int top = sta.top();
                sta.pop();
                int second = sta.top();
                sta.pop();
                int tmp = top * second;
                sta.push(tmp);
            } else if(now == "/"){
                int top = sta.top();
                sta.pop();
                int second = sta.top();
                sta.pop();
                int tmp = second / top;
                sta.push(tmp);
            } else {
                sta.push(stoi(now));
            }
        }
        return sta.top();
    }
};
