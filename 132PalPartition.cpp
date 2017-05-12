/* 给定一个字符串，将其划分成几个回文子串，求最小的划分方案
 * Solution： DP， 两个二维的数组，is_par[i][j] : 表示i到j是不是回文串。 cut[i] 表示str[i...size]的最小cut数量
 * 最后返回cut[0]
 * 解法二，直接使用一个cut[i],表示str[0,1...i]的最下cut数量。
 */

class Solution {
public:
    int minCut(string s) {
        
    }
};
