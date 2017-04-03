/*Problem: the total ways to climb the stairs.
 *Solution: DP, the Fibonacci.
 */
#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 1;
        int ret[n+1];
        ret[0] = 1;
        ret[1] = 1;
        for(int i=2; i<=n; ++i){
            ret[i] = ret[i-1] + ret[i-2];
        }
        return ret[n];
    }
};

int main(){ 
    //AC
}
