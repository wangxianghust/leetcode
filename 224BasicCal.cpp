/* 模拟一个计算器，包含（）， + -，空格（要忽略），假设输入都是合法的，输入时non-negative-int
 * Solution：先转化为后缀表达式，再计算吧
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        string suf = suffix(s);
        stack<int> sta;
        for(int i=0; i<suf.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9') sta.push(s[i]-'0');
            else if(s[i] == '+'){
                int op1 = sta.top();
                sta.pop();
                int op2 = sta.top();
                sta.pop();
                sta.push(op1+op2);
            } else if(s[i] == '-'){
                int op1 = sta.top();
                sta.pop();
                int op2 = sta.top();
                sta.pop();
                sta.push(op1-op2);
            }
        }
        return sta.top();
    }
private:
    string suffix(string &s){
        int size = s.size();
        string suf;
        stack<char> oper;
        for(int i=0; i<size; ++i){
            if(s[i] == ' ')continue;
            if(s[i] >= '0' && s[i] <= '9') suf.push_back(s[i]);
            if(s[i] == '(') {
                while(s[i++] != ')'){
                    if(s[i] >= '0' && s[i] <= '9') suf.push_back(s[i]);
                    if(s[i] == '-' || s[i] == '+') oper.push(s[i]);
                    //++i;
                }
            }
            if(s[i] == ')'){
                while(!oper.empty()){
                    char top = oper.top();
                    oper.pop();
                    suf.push_back(top);
                }
            }
        }
        return suf;
    }
};
