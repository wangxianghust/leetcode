/* Modified the variable debug to determine whether come into the debug model
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string indent = "";

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> combination;
        combinationSum(candidates, target, combination, ret, 0);
        return ret;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<int> &combination, vector<vector<int> > &ret, int begin){
        if(target == 0){
            ret.push_back(combination);
            for(auto i: combination) cout << i << "--"; cout << endl;
            return;
        }
        for(int i=begin; i<candidates.size() && target >= candidates[i]; ++i){
            if(i == begin || candidates[i] != candidates[i-1]){
                enter(candidates, i);
                combination.push_back(candidates[i]);
                combinationSum(candidates, target-candidates[i], combination, ret, i+1);
                combination.pop_back();
                print(combination);
            }
        }
    }
private:
    static bool debug;
    void enter(vector<int> &candidates, int i){
        if(debug){
            cout << indent << "Entering " << candidates[i] << endl;
            indent += "|  ";
        }
     }
    void print(vector<int> &combinations){
        if(debug){
            indent = indent.substr(3);
            cout << indent << "can : ";
            for(auto i : combinations) cout << i << " ";
            cout << endl;
        }
    }
public:
    void print(vector<vector<int>> &ret){
        for(auto i : ret){
            for(auto j : i)cout << j << " ";
            cout << endl;
        }
        cout << "---" << endl;
    }

};

bool Solution::debug = true;


int main(){
    freopen("40test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int target;
        int size;
        cin >> target >> size;
        vector<int> can;
        for(int i=0; i<size; ++i){
            int c;
            cin >> c;
            can.push_back(c);
        }
        auto ret = Sol.combinationSum2(can, target);
        Sol.print(ret);
    }
}


