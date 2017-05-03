/* 给定2*n + 1 个数字，除一个数字出现一次外，其他数字都出现两次，求这个数字？
 * Solution: 异或，所有数字在一起异或，则相同的数字均为0，剩下的就是那个不同的数字
 */

#include <vector>

using namespace std;

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int size = A.size(); 
        if(size == 0) return 0; //by OJ
        if(! (size & 0x1)) return -1; //the size is not odd
        int ret = A[0];
        for(int i=1; i<size; ++i){
            ret ^= A[i];
        }
        return ret;
    }
};
