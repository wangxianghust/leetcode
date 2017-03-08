#include <iostream>
#include <string>
#include <set>

using namespace std;

const int MAXNUM = 200;

void print(set<char> &s){
    for(auto i : s) cout << i << " ";
}

int LengthOfLongestSubstring(string s){
    int size = s.size();
    set<char> substring;
    int ret = 0;
    for(int i=0; i<size; ++i){
        substring.clear();
        for(int j=0; j<MAXNUM && i+j <size; ++j){
            char tmp = s[i+j];
            if(substring.find(tmp) == substring.end()){
                substring.insert(tmp);
            } else {
                //cout << "test" << endl;
                //print(substring);
                break;
            }
            if(substring.size() > ret)ret = substring.size();
        }
    }
    return ret;
}

int main(){
    string s = "pwwkew";

    cout << LengthOfLongestSubstring(s) << endl;
}
