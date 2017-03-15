/*Problem：求所有string的common prefix
 * 思路：取第一个开始遍历，对于每一个位置i，我们都检测是不是所有的string合格，
 * 合格继续，不合格return
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.empty()) return "";
        if(strs[0] == "") return prefix;
        for(int i=0; i<strs[0].size(); ++i){
            char c = strs[0][i];
            for(int index=1; index < strs.size(); ++index){
                if(i >= strs[index].size() || strs[index][i] != c){
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};

int main(){
    Solution Sol;
    freopen("14test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        int size;
        cin >> size;
        vector<string> strs;
        for(int j=0; j<size; ++j){
            string s;
            cin >> s;
            strs.push_back(s);
        }
        cout << Sol.longestCommonPrefix(strs) << endl;
    }
}
