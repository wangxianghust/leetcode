/*问题：问一个字符串表示的是否是合法的数字
 *方法：首先清楚哪些是合法的吧，然后解决方案是用e和.进行划分，分别判定
 *本题目的是想对DFA进行练习，可是what is valid number, it is not clear...
 *BAD Problem,just see see.
 *最后两行，skip space then test whether the last is 0.
 */

#include <string>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        int size = s.size();
        while(i<size && s[i] == ' ') ++i;
        if(s[i] == '+' || s[i] == '-') ++i;
        int num_num = 0; //number of number
        int point_num = 0; //number of point .
        for( ; (s[i] >= '0' && s[i] <= '9')||s[i] == '.'; ++i ){
            s[i] == '.' ? ++point_num : ++num_num;
        }
        if(point_num > 1 || num_num < 1) return false; //至少有一个数字，至多有一个点
        
        if(s[i] == 'e'){
            ++i;
            if(s[i] == '+' || s[i] == '-') ++i;
            num_num = 0;
            for(; s[i] >= '0' && s[i] <= '9'; ++i) ++num_num;
            if(num_num < 1) return false;
        }
        while(i<size && s[i] == ' ') ++i;
        return s[i] == 0; //Important : 0 denotes the end of string
    }
};

int main(){
    freopen("65test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        string s; cin >> s;
        cout << Sol.isNumber(s) << endl;
    }
}
