/* 将一个区间内的数字按位与求出结果如[9,11]里面共有(9,10,11)三个数字，二进制为1_001 1_010 1_011
 * 结果哦是1_000为8
 * Solution: 从上面的计算可以看出，只要 m!=n，则最低&结果肯定为0(因为奇偶性)，每次比较完将m,n各
 * 向右移动一位，直到m == n，m << count 即可得到结果。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            ++count;
        }  
        return m << count;
    }
};

int main(){
    
}
