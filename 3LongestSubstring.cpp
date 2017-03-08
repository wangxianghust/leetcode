#include <iostream>
#include <string>
#include <set>
#include <vector>

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

int LengthOfLongestSubstring_2(string s){
    vector<int> char_book(256, -1); //to remember every char first appeared index.
    int size = s.size();
    int max =0;
    int idx = -1;
    for(int i=0; i<size; ++i){
        if(char_book[s[i]] > idx){
            idx = char_book[s[i]];
        }
        if(i - idx > max){
            max = i - idx;
        }
        char_book[s[i]] = i;
    }
    return max;
}

int main(){
    string s = "pwwkew";

    cout << LengthOfLongestSubstring(s) << endl;
    cout << "---Another method---" << endl;
    cout << LengthOfLongestSubstring_2(s) << endl;
}
