/*直观的想法，对于不同长度的string, 使用size个for循环即可，但是
 * 开始我们不知道size啊，tricky点就是用用pre_ret保存上次的结果，不断添加
 * 迭代到ret中。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        int size = digits.size();
        vector<string> ret{""};
        const string book[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};
        for(int i=0; i<size; ++i){
            string letters = book[digits[i] - '0'];
            if(letters.size() == 0) continue;
            vector<string> pre_ret; //the local var in for loop means that it will be cleared every iterarion.
            for(int j=0; j<letters.size(); ++j){
                for(int k=0; k<ret.size(); ++k){
                    pre_ret.push_back(ret[k] + letters[j]);
                }
            }
            ret.swap(pre_ret);
        }
        return ret;
    }
};
 
void print(vector<string> ret){
    for(auto i: ret){
        cout << i << "-->";
    }
    cout << endl;
}

int main(){
    freopen("17test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        string s;
        cin >> s;
        print(Sol.letterCombinations(s));
    }
}
