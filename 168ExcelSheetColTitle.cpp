/* 给定一个正整数，返回其在Excel中的表现形式，1 A  26 Z 27 AA
 * Solution：形式上这就是一个26进制的计数器
 */

#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        if(n < 1) return ret;
        while(n){
            int offset = n%26;
            char c('Z');
            if(offset) c = 'A' + offset - 1;
            ret = c + ret;
            n /= 26;
            if(offset == 0) --n;  //hold this case.
        }
        return ret;
    }
};
