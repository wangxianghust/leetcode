/* 给定一个int,按bit进行翻转，给出翻转后的值
 * Solution:直接对n每次取最后一位x然后右移，再取一个变量，每次左移然后或上x
 */

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int m(0);
        for(int i=0; i<32; ++i,n >>= 1){
            m <<= 1;
            int x = n & 0x1;
            m |= x;
        }
        return m;
    }
};

int main(){
    Solution Sol;
    uint32_t n = 43261596;
    cout << Sol.reverseBits(n) << endl;
}
