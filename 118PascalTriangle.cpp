/* 给定整数n,生成n levels 杨辉三角形
 * Solution：从上至下计算即可，下一层的数字等于肩膀上两个数字之和，首尾都是1
 * 重点是，level.resize(i+1), resize 函数确定该层数量
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      if(numRows == 0) return vector<vector<int>>();
      vector<vector<int>>  ret(numRows);
      ret[0].push_back(1);
      for(int i=1; i<numRows; ++i){
          ret[i].resize(i+1);
          ret[i][0] = 1;
          ret[i][i] = 1;
          for(int j=1; j<i; ++j){
              ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
          }
      }
      return ret;
    }
};
