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
        stack<long> sta;
        int num = 0;
        for(int i=0; i<suf.size(); ++i){
            if(isdigit(suf[i])) {
                num = num*10 + suf[i]-'0';
            } else if (suf[i] == '$'){
                sta.push(num);
                num = 0;
            }
            else if(suf[i] == '+'){
                int op1 = sta.top();
                sta.pop();
                int op2 = sta.top();
                sta.pop();
                sta.push(op2+op1);
            } else if(suf[i] == '-'){
                int op1 = sta.top();
                sta.pop();
                int op2 = sta.top();
                sta.pop();
                sta.push(op2-op1);
            } else {
                cout << s[i] << "-->" << i << "Error Input" << endl;
            }
        }
        return sta.top();
    }
public:
    string suffix(string &s){
        int size = s.size();
        string suf;
        stack<char> oper;
        for(int i=0; i<size; ++i){
            char now = s[i];
            //cout << now << endl;
            switch(now){
                case ' ' : continue;
                case '(' : oper.push(now); break;
                case ')' : 
                           while(oper.top() != '('){
                               char t = oper.top();
                               suf.push_back(t);
                               oper.pop();
                               //cout << t << "--" << endl;
                           }
                           //cout << suf << "->" << endl;
                           oper.pop();
                           break;
                case '+':
                case '-':
                           while(!oper.empty()){
                               char t = oper.top();
                               if(priority(t) >= priority(now)){
                                    suf.push_back(t);
                                    oper.pop();
                                    //t = oper.top();
                               } else break;
                           }
                           oper.push(now);
                           break;
                default: suf.push_back(now); 
                         if(i+1==size || !isdigit(s[i+1])) suf.push_back('$');
                         break; //default is number. 由于要判定123是123不是1，2，3
            }            
        }
        while(!oper.empty()){
                    char top = oper.top();
                    oper.pop();
                    suf.push_back(top);
                }
        return suf;
    }
private:
    int priority(char t){
        switch(t){
            case '+' : return 1;
            case '-' : return 1;
            default : return 0;
        }
    }
    bool isdigit(char c){
        return c >= '0' && c <= '9';
    }
};

int main(){
    Solution Sol;
    string s = " 12-1 + 22 + (3+2)";
    s = "2147483647";
    cout << Sol.suffix(s) << endl;
    cout << "suffix is ok" << endl;
    cout << Sol.calculate(s) << endl;
}
