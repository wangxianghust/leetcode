/*判断括号是否合法，首先了解什么是不合法。
 * 同一个括号左右数量不匹配，两种括号的交叉使用([)], 优先级([])
 * 所以使用small, medium, big来记录三种括号，左括号加一，右括号减一
 */
//注意本题的判断认为([])是合法的，不考虑优先级，所以使用stack进行模拟。

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid_(string s) {
        int small = 0;
        int medium = 0; 
        int big = 0;
        int size = s.size();
        bool flag = true;
        for(int i=0; i<size; ++i){
            char now = s[i];
            if(now == '('){
                ++small;
            } else if(now == ')'){
                --small;
                if(small < 0) flag = false;  //case ())
            } else if(now == '['){
                if(small != 0) flag = false; // case (([))
                ++medium;
            } else if(now == ']'){
                if(small != 0) flag = false; // case ((]))
                --medium;
                if(medium < 0) flag = false; // case []]
            } else if(now == '{'){
                if(small != 0 || medium != 0) flag = false; // case ({}) [{}]
                ++big;
            } else {
                if(small != 0 || medium != 0) flag = false; // case (}) [}]
                --big;
                if(big < 0) flag = false; // case {}}//
            }
            if(false == flag) return false;
        }
        if(small != 0 || medium != 0 || big != 0) flag = false; // case [  }  
        return flag;
    }

public:
    bool isValid(string s) {
        stack<char> sta;
        int size = s.size();
        for(int i=0; i<size; ++i){
            char now = s[i];
            switch(now){
                case '(':
                case '[':
                case '{':
                    sta.push(now);
                    break;
                case ')':
                    if(sta.empty() || sta.top() != '(') return false; 
                    else sta.pop();
                    break;
                case ']':
                    if(sta.empty() || sta.top() != '[') return false; 
                    else sta.pop();
                    break;
                case '}':
                    if(sta.empty() || sta.top() != '{') return false; 
                    else sta.pop();
                    break;
                default: ;
            }
        }
        return sta.empty();
    }

};

int main(){
    freopen("20test.txt", "r", stdin);
    int total;
    cin >> total;
    string s;
    Solution Sol;
    for(int i=0; i<total; ++i){
        cin >> s;
        cout << Sol.isValid(s) << endl;
    }
}
