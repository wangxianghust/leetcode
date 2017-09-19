/* 给定一个字符串，求对这个字符串划分后，得到所有的子串都是回文串，求这样的划分集合
 * 回溯法，枚举所有的解空间，DFS + 剪枝(判断是不是回文串)
 * DP
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size() == 0) return ret;
        vector<string> path;
        helper(0, s, path, ret);
        return ret;
    }

    void helper(int idx, string &s, vector<string> path, vector<vector<string> > &ret){
        if(idx == s.size()){
            ret.push_back(path);
            return;
        }
        for(int i=idx; i<s.size(); ++i){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i-idx+1));
                helper(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[end--] != s[start++]) return false;
        }
        return true;
    }
};
