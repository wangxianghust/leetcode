/* 统计一个unsigned int中转为二进制，1的数量
 * Solution，进行 n&(n-1)操作，每次会消除一个1
 */

#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            n &= (n-1);
            ++ret;
        }
        return ret;
    }
};

int main(){
    
}
