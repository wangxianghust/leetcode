/* 幂运算模拟
 * 开始的方案是先求幂值，再进行求余运算，但是TLE，所以要用到模运算的性质
 * (a*n)%b = ( (a%b)*(n%b) ) % b;
 */

#include <iostream>
#include <climits>

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n){
        if(n == 0) return 1%b;
        if(n == 1) return a%b;
        if(n < 0) return -1;
        long power = fastPower(a, b, n>>1); //NOTICE, there must be long, int will WA
        long ret = ( power * power )%b;
        if(n & 0x1) ret = ( ret*(a%b) )%b;
        return (int)ret;
    }
    int fastPower_(int a, int b, int n){
        int ret = Power(a, n);
        return (int)(ret % b);
    }
    double Power(int a, int n) {
        // write your code here
        if(n == 0) return 1;
        if(n < 0 && n != INT_MIN){
            n = -n;
            a = 1/a;
        }
        return (n & 0x1) ? a*Power(a*a,n>>1) : Power(a,n>>1);
    }
};
