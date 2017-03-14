#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        unordered_map<char, int> book{ {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1} };
        ret = book[s.back()];
        for(int i = s.length()-1-1; i >= 0; --i){
            if(book[s[i]] < book[s[i+1]]){ //high index is smaller than low index, mini
                ret -= book[s[i]];
            } else {
                ret += book[s[i]];
            }
        }
        return ret;
    }
};

int main(){
    Solution Sol;
    freopen("13test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        string s;
        cin >> s;
        cout << Sol.romanToInt(s) << endl;
    }
}
