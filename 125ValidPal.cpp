/*判定一个string是不是回文串，只用判断字母和数字，忽略空格和标点符号,忽略大小写等
 * Solution：start, end双指针即可，要注意start<end成立；isalnum:判断是不是字母，数字， toupper:将字母变成大写
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
       int size = s.size();
       int start = 0; 
       int end = size - 1;
       while(start < end){
           while( (start < end) && !isalnum(s[start]) ) ++start;
           while( (start < end) && !isalnum(s[end]) ) --end;
           if(toupper(s[start]) != toupper(s[end])){
               return false;
           } else {
               ++start;
               --end;
           }
       }
       return true;
    }
};
