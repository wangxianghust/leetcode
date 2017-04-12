/*Problem: Find the longest substring, which parenthess is valid.
 * Solution: Use stack to sumulation, ONLY ONE case that when stack is empty and the coming char is ')'
 * the num needed to updae.
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    //ONLY one pass, the second pass for different start is no use.
    int longestValidParentheses(string s) {
        int ret = 0;
        stack<int> sta; //save the index of correspond char (),why, cause save ( or  ) have no more info, use index can get char too.
        for(size_t i=0; i<s.size(); ++i){
            char now = s[i];
            if('(' == now){
                sta.push(i);
            } else {
                if(!sta.empty() && s[sta.top()] == '('){
                    sta.pop();
                    int pre_index = sta.empty() ? -1 : sta.top();
                    int tmp = i - pre_index;
                    if(ret < tmp) ret = tmp;
                } else {  //sta.empty() or sta.top() == ')', but when sta is empty, we won't push ')' into stack, so the second case NOT happen.
                    sta.push(i);
                }
            }
        }
        return ret; //return the par length, not num.
    }
};

int main(){
    //AC
    Solution Sol;
    int ret = Sol.longestValidParentheses("(()()))()(((())))))");
    cout << ret << endl;
}
