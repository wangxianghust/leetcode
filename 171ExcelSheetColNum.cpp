/* 将A 1  B 2  AA 27这样进行转化
 * Solution：额，直接计算ba
 */

#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int size(s.size());
        if(size == 0) return -1;
        int ret = 0;
        for(int i=0; i<size; ++i){
            ret = ret*26 + s[i] - 'A' + 1;
        }
        return ret;
    }
};
