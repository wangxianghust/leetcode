/* happy number定义，不断计算数字和，最后结果为1就是happy number,否则不是 eg 81--> 65 --> 61 ---> 37 --> 58...
 * Solution: 有一点，如果一个数不是happy number，它必然会进入一个循环，why? 因为一次计算，值是减小的，eg 999，又数字是有限的，故必然重复
 * 1. 直观的解法，不是happy number会陷入循环，使用hashset检测是否有重复，有为false
 * 2. 在判断链表是否有环的过程中，我们用过slow，fast两个指针，可以使用这个思想
 * 3. 也可以while(n > 6) {} 数字6的确定需要基于观察，原因是数字是一直减少的
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy_(int n) {
        unordered_set<int> found;
        while( (found.insert(n)).second ){ //return-val second denotes if insert successful or not.
            int ret = calculate(n);
            if(n == 1) return true;
            n = ret;
        }
        return false;
    }

    bool isHappy(int n){
        int slow(n),fast(n);
        do{
            slow = calculate(slow);
            fast = calculate( calculate(fast) );
        } while(slow != fast);
        return slow == 1;
    }
private:
    int calculate(int n){
        int ret = 0;
        while(n){
            int tmp = n % 10;
            ret += tmp * tmp;
            n /= 10;
        }
        return ret;
    }
};
