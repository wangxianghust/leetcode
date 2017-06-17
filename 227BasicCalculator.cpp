/* 设计一个计算器，实现基本的+ - * /功能，忽略空格
 * 此次做一个拓展，实现一个计算器，包含（）+ - * /等功能。
 * 思路是转化为后缀表达式进行计算
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <exception>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        string suf = constructSuffix(s);
        stack<int> ret;
        int num = 0;
        for(int i=0; i<(int)suf.size(); ++i){
            char now = suf[i];
            if(isdigit(now)){
                num = num * 10 + now - '0';
            } else if(now == '$'){
                cout << num << endl;
                ret.push(num);
                num = 0;
            } else if(isOper(now)){
                int op2 = ret.top();
                ret.pop();
                int op1 = ret.top();
                ret.pop();
                cout << "-->" << operation(op1, op2, now) << endl;
                ret.push(operation(op1, op2, now));
            } else {
                throw exception();
            }
        }
        return ret.top();
    }
public:
    string constructSuffix(string &s){
        //support long num, use $ denote the end of a num.
        stack<char> oper;
        string suf;
        int size(s.size());
        for(int i=0; i<size; ++i){
            switch(char now = s[i]){
                case ' ': continue;
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                    suf += now;
                    if(i+1 == size || !isdigit(s[i+1])) suf += '$'; //'$' is the end of number;
                    break;
                case '(':
                    oper.push(now);
                    break;
                case ')':
                    while(oper.top() != '('){
                        suf += oper.top();
                        oper.pop();
                    } 
                    oper.pop();
                    break;  
                case '+': case '-': case '*' : case '/':
                    while(!oper.empty()){
                        char op = oper.top();
                        if(priority(op) >= priority(now)){
                            suf += op;
                            oper.pop();
                        } else break;
                    }
                    oper.push(now);
                    break;
                default: cerr << "Error Input" << endl; throw exception();
            }       
        
        }
        while(!oper.empty()){
            suf += oper.top();
            oper.pop();
        }
        return suf;
    }
private:
    int priority(char c){
        switch(c){
            case '*':
            case '/':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    }

    bool isdigit(char c){
        return c >= '0' && c <= '9';
    }

    bool isOper(char c){
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
    int operation(int a, int b, char op){
        switch(op){
            case '+' : return a+b;
            case '-' : return a-b;
            case '*' : return a*b;
            case '/' : return a/b;
            default : throw exception();
        }
    }
};

int main(){
    Solution Sol;
    string s = "2* (3+2) - 4/2 +1 ";
    //s = "2147483647";
    cout << Sol.constructSuffix(s) << endl;
    cout << "suffix is ok" << endl;
    cout << Sol.calculate(s) << endl;
}
