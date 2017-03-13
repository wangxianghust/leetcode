#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char> > book(numRows, vector<char>());
        bool direction = true;
        int row = 0;
        for(int i=0; i < s.size(); ++i){
            book[row].push_back(s[i]);
            if(direction) ++row;
            else --row;
            if(row == numRows-1)direction = false;
            if(row == 0)direction = true;
        }
        string ret("");
        for(auto i : book){
            for(auto j : i){
                ret += j;
            }
        }
        return ret;
    }
};

int main(){
    freopen("6test.txt", "r", stdin);
    Solution Sol;
    int total;
    cin >> total;
    string s;
    int rowNum;
    for(int i=0; i<total; ++i){
        cin >> s;
        cin >> rowNum;
        //cout << s << rowNum << endl;
        cout << Sol.convert(s, rowNum) << endl;
    }
}
