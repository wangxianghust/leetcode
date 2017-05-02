/* 求数组中的逆序对
 * Solution: 在归并排序的时候有统计过，修改merge-sort即可
 * 注意要点：二分之后，一是对于左右两个数组，要从后向前统计；二是统计完不忘排序
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        int size = A.size();
        if(size <= 1) return 0;
        int count = 0;
        merge_static(A, 0, size-1, count);
        return count;
    }

private:
    void merge_static(vector<int> &A, int low, int high, int &count){
        if(low == high) return;
        int mid = low + (high - low)/2;
        merge_static(A, low, mid, count);
        merge_static(A, mid+1, high, count);
        merge(A, low, mid, high, count);
    }

    void merge(vector<int> &A, int low, int mid, int high, int &count){
        vector<int> left,right;
        for(int i=low; i<=mid; ++i) left.push_back(A[i]);
        for(int i=mid+1; i<=high; ++i) right.push_back(A[i]);
        int k(high), i(left.size()-1), j(right.size()-1); //from right--->left to visit.
        for( ; i>=0 && j>=0; ){
            if(left[i] > right[j]){
                count += j+1;
                A[k--] = left[i--];  //static the reverse num and sort at the same time.
            } else {
                A[k--] = right[j--];
            }
        }
        for(; j>=0; --j) A[k--] = right[j];
        for(; i>=0; --i) A[k--] = left[i];
    }
};
