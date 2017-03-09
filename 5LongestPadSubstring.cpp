#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length();
        vector<vector<bool> > isPad(size, vector<bool>(size, false));
        //initialization
        int maxLeft = 0;
        int maxLen = 1;

        for(int i=0; i<size; ++i) {
            isPad[i][i] = true;
        }
        for(int i=0; i<size-1; ++i){
            if(s[i] == s[i+1]){
                isPad[i][i+1] = true;
                maxLeft = i;
                maxLen = 2;
            }
        }
        
        for(int len=3; len<=size; ++len){
            for(int start=0; start<size-len+1; ++start){
                int end = start + len -1;
                if(isPad[start+1][end-1] && s[start] == s[end]){
                    isPad[start][end] = true;
                    if(end - start + 1 > maxLen){
                        maxLen = end-start+1;
                        maxLeft = start;
                    } 
                }
            }
        }
        if(maxLen > 2){

        }
        return s.substr(maxLeft, maxLen);
    }
};

int main(){
    string s("ccc");
    Solution Sol;
    cout << Sol.longestPalindrome(s) << endl;
}
