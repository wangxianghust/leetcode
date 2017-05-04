/* 给定一个字符串，根据偏移量来旋转，如abcde,offset=2时，deabc
 * Solution：1. reverse后offset个， 2.reverse 前(len-offset)个， 3. reverse 整个
 */

#include <string>
#include <algorithm>
#include <exception>

using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        int size = str.size();
        if(offset < 0) throw exception();
        if(size == 0) return;
        if(offset > size) offset %= size;
        reverse(str.begin(), str.begin()+(size-offset));
        reverse(str.end()-offset, str.end());
        reverse(str.begin(), str.end());
    }
};

