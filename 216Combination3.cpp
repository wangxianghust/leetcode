/* 给定k,求k个数字的和为n，其中数字均为1~9,数字不带重复的
 * Solution: 回溯 + 剪枝
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> group;
        int sum = 0;
        combination(ret, group, sum, n, k, 1);
        return ret;
    }
private:
    void combination(vector<vector<int>> &ret, vector<int> &group, int &sum, int n, int k, int begin){
        //cout << sum << endl;
        if( (sum > n)||(group.size() > k) ) return;
        if( (sum == n)&&(k == group.size()) ){
            ret.push_back(group);
            return;
        }
        for(int i=begin; i<10; ++i){
            //cout << i << endl;
            sum += i;
            group.push_back(i);
            combination(ret, group, sum, n, k, i+1);
            sum -= i;
            group.pop_back();
        }
    }
};

void print(vector<vector<int>> ret){
    for(auto r : ret){
        for(int i : r) cout << i << " ";
        cout << endl;
    }
    //cout << endl;
}

int main(){
    Solution Sol;
    auto ret = Sol.combinationSum3(3,9);
    print(ret);
}
