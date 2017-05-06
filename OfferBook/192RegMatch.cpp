/*模拟正则匹配，？可以匹配任何单个字符，A*匹配0个或多个A
 * Solution: 自动机，NFA可以，使用数组保存状态也可以，book[i][j]表示s,p长度为别
 * 为i,j，此时能否匹配？
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */

    bool isMatch(const char *s, const char *p){
        int s_len = getLen(s);
        int p_len = getLen(p);
        vector<vector<bool> > book(s_len+1, vector<bool>(p_len+1,false));
        book[0][0] = true;
        for(int j=0; j<p_len; ++j) book[0][j+1] = book[0][j] && ( *(p+j) == '*');   
        for(int i=0; i<s_len; ++i){
            for(int j=0; j<p_len; ++j){
                if(*(s+i) == *(p+j) || *(p+j) == '?'){
                    book[i+1][j+1] = book[i][j];
                }
                if(*(p+j) == '*'){
                    book[i+1][j+1] = book[i+1][j] || book[i][j+1];
                }
            }
        }
        return book[s_len][p_len];
    }

    int getLen(const char *s){
        int len = 0;
        while(*(s++) != '\0') ++len;
        return len;
    }

    bool isMatch_(const char *s, const char *p) {
        // write your code here
        if(*s == '\0' && *p == '\0') return true;
        if(*s != '\0' && *p == '\0') return false; //pattern is over.
        //then *p must != '\0', but *s can not determine.
        if(*(p+1) == '*'){
            if(*p == *s || (*p =='?' && *s != '\0')){
                //A* match A,  A* match A and stay state, not match
                return isMatch(s+1, p+2) || isMatch(s+1, p) || isMatch(s, p+2);
            } else {
                return isMatch(s, p+2);
            }
        }
        if(*p == *s || (*p =='?' && *s != '\0')) return isMatch(s+1, p+1);
        else return false;
    }
};

int main(){
    const char* s = "aa";
    const char* p = "a";
    Solution Sol;
    cout << Sol.isMatch(s, p) << endl;
}
