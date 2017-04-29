/* 计算在一个32位整数的二进制表达式中有多少个1
 * Solution: tricy, 每次通过 n&(n-1)会消除一个二进制中的1，所以
 * 不断的进行上述运算，运算次数是1的个数
 */

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count(0);
        while(num){
            num &= num-1;
            ++count;
        }
        return count;
    }
};
