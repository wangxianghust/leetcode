/* 给一个string和dict,问string能否被dict中的单词切分。
 * Solution： DP， dp[i]代表从开始到目前是否能够切分，每次计算新的dp[i+1]都需要尝试在每个点后切，一旦遇到合法的
 * 就设置dp[i+1]=true，这样可以减少运算。
 *
 * 思路二：BFS，queue<int> 保存访问的index, unordered_set<int> 保存访问过的节点继续被访问，当index = size-1,true.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int size = s.size();
        if(wordDict.size() == 0) return false;
        vector<bool> dp(size+1, false); 
        dp[0] = true;
        //the length of s
        for(int i=1; i<=size; ++i){
            //select start index
            for(int j=i-1; j>=0; --j){
                if(dp[j]){
                    string tmp = s.substr(j, i-j);
                    if(dict.find(tmp) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
