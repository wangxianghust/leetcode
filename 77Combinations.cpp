/*Problem: Give two integer n and k, return all possible combinations of k numbers out of 1,2,3,4,5...n
 * Solution: backtracking
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> combination;
        combine(n, k, ret, combination, 1); 
        return ret;
    }
private:
    void combine(int n, int k, vector<vector<int> > &ret, vector<int> &combination, int start){
        if(k == 0){
            ret.push_back(combination);
            //combination.clear();
            return;
        }

        for(int i=start; i<=n; ++i){
            combination.push_back(i);
            combine(n, k-1, ret, combination, i+1);
            combination.pop_back();
        }
    }
public:
    void print(vector<vector<int> > ret){
        for(auto item : ret){
            for(int i : item) cout << i << " ";
            cout << endl;
        }
    }
};

int main(){
    Solution Sol;
    auto ret = Sol.combine(5, 3);
    Sol.print(ret);
}
