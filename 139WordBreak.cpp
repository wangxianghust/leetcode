/* 给一个string和dict,问string能否被dict中的单词切分。
 * Solution： DP， dp[i]代表从开始到目前是否能够切分，每次计算新的dp[i+1]都需要尝试在每个点后切，一旦遇到合法的
 * 就设置dp[i+1]=true，这样可以减少运算。
 *
 * 思路二：BFS，queue<int> 保存访问的index, unordered_set<int> 保存访问过的节点继续被访问，当index = size-1,true.
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
    }
};
