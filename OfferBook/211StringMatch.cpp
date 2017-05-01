/* 判断两个字符串通过置换是否可以得到，也就是字符的种类和数量是完全相同的
 * Solution: 通过unordered_map 可以实现，同时自己建立一个hash表也好
 * string1出现则加1，string2出现则减1，最后遍历hash表所有的索引为0即可
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        if(A.size() != B.size()) return false;
        vector<int> book(256, 0);
        for(int i=0; i<A.size(); ++i){
            book[A[i]]++;
            book[B[i]]--;
        }
        for(int i=0; i<256; ++i){
            if(book[i] != 0) return false;
        }
        return true;
    }
};
