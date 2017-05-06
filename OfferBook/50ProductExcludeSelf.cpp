/* 给定一个数组A,求B[i] = A[0]*A[1]*..A[i-1]*A[i+1]*...A[size-1]，要求是不能使用出发来做
 * Solution: 所以就是动态规划啊，需要两个数组保存，front[i]表示前i个乘积，back[i]表示从尾巴到i的乘积
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        int size = nums.size();
        vector<long long> ret(size);
        if(size == 0) return ret;
        vector<long long> back(size+1, 1);//from back to calculate, back[2] means A[size-1]*A[size-2];
        vector<long long> front(size+1, 1);//front[0] is initialized to 1, and front[1] denote A[0];
        for(int i=0; i<size; ++i){
            front[i+1] = front[i] * nums[i];
        }

        for(int i=0; i<size; ++i){
            back[i+1] = back[i] * nums[size-i-1];
        }

        for(int i=0; i<size; ++i){
            ret[i] = front[i] * back[size-i-1];
        }
        return ret;
    }
};
