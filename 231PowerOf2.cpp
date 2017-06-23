/*输入一个数，判定其是不是2的幂
 * Solution：直观的，2的幂也就是二进制表达只含有一个1，也就是 n = n&(n-1) = 0;
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&(n-1)) == 0;
    }
};
