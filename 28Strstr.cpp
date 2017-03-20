#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    //The complexity is O(n^2), KMP http://blog.csdn.net/v_july_v/article/details/7041827 can get better results.
    int strStr(string haystack, string needle) {
        if(haystack.empty() && needle.empty()) return 0;
        //if(haystack.empty() || needle.empty()) return -1;  //cause a '\space' is 0 in the test...
        for(int i=0; i<haystack.size()-needle.size()+1; ++i){
            bool flag = true;
            int j = 0;
            int tmp = i;
            for( ; j<needle.size(); ){
                if(haystack[tmp++] != needle[j++]){
                    flag = false;
                    break;
                }
            }
            if(flag) return tmp-j;
        } 
        return -1;    
    }
};

int main(){
    freopen("28test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        string haystack, needle;
        cin >> haystack >> needle;
        cout << haystack << " " << needle << endl;
        cout << Sol.strStr(haystack, needle) << endl;
    }
}

