/* 给定整数n,生成杨辉三角形中的第n层
 * Solution：从上至下计算即可，下一层的数字等于肩膀上两个数字之和，首尾都是1
 * 重点是题目要求只能使用k的空间，所以先开一个k的vector level, level[0] =1 ， 其实代表第一层
 * 然后计算第二层第三层，level[0~1], level[0~3]...，每次计算的时候注意从尾巴向前计算。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1, 0);
        ret[0] = 1;
        for(int i=0; i<rowIndex; ++i){
            for(int j=i+1; j>0; --j){
                ret[j] = ret[j] + ret[j-1];
            }
        }
        return ret;
    }
};
