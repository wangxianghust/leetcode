/*每当看到列出所有组合的情况，需要想到DFS，递归，回溯
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return vector<string>();
        generate("", n, n);
        return ret;
    }

private:
    //left is the number of left parenthesis can be used.
    void generate(string combination, int left, int right){
        //the right used more than left, invalid case.
        if(left > right) return;
        if(left > 0) generate(combination+"(", left-1, right);
        if(right > 0) generate(combination+")", left, right-1);
        if(left == 0 && right == 0){
            ret.push_back(combination);
            return;
        }
    }
private:
    vector<string> ret;
public:
    void retClear(){
        ret.clear();
    }
};

void print(vector<string> ret){
    for(auto i: ret) cout << i << "---";
    cout << endl;
}

int main(){
    freopen("22test.txt", "r", stdin);
    int total;
    cin >> total;
    int c;
    Solution Sol;
    for(int i=0; i<total; ++i){
        cin >> c;
        auto ret = Sol.generateParenthesis(c);
        print(ret);
        Sol.retClear();
    }
}
