/* 给定一个string s,可以在s的前面添加字符使其成为一个回文字串，求最小长度的这个字串
 * Solution:直观上的解法就是，找出s的一个最长前缀，该前缀是回文字串，如 abccbat,那么构造的话，
 * 只要在前面加一个t就ok了，这是暴力解法。
 * 同时，结合前缀匹配，想到了KMP,可以用 reverse(s) + '#' + s。然后look-up表的最后一个就是结果。
 * KMP算法待定。
 */
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
       string p(s);
       reverse(p.begin(), p.end());
       //判断后缀是否是前缀，从最长的开始计算
       int len = s.size();
       int i = len;
       for( ; i>0; --i){
           if(p.substr(len-i) == s.substr(0,i)) break;
       }
       return p.substr(0,len-i) + s;
    }
};

int main(){
    Solution Sol;
    string s = "abcd";
    s = "dedabc";
    string ret = Sol.shortestPalindrome(s);
    cout << ret << endl;
}
