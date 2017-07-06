/*
 * 将数字的各个数相加，直至得到一个位数，要求不使用循环，递归
 * Solution:需要一个推导公式，   n mod 9 = (n的各个digit和) mod 9
*/

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        int ret = num % 9;
        return (ret == 0) ? 9 : ret;
    }
};
