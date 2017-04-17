/* Problem: A~Z is decoded as 1~26, now a num string is given, how to get the total ways to decode.
 * Solution: DP
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(size == 0) return 0;
        vector<int> ret(size+1, 0); //the pre-num string ways?
        ret[0] = 1;
        ret[1] = (s[0] == '0' ? 0 : 1);
        for(int i=2; i<=size; ++i){
            string one = s.substr(i-1,1);
            string two = s.substr(i-2,2);
            if("1" <= one && one <= "9"){
                ret[i] += ret[i-1];
            }
            if("10" <= two && two <= "26"){
                ret[i] += ret[i-2];
            }
        }
        return ret[size];
    }
};

int main(){
    Solution Sol;
    string s("112");
    cout << Sol.numDecodings(s) << endl;
}
