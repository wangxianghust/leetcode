#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.size() == 0) return ret;
        unordered_map<string, int> book;
        for(auto i : words){
            ++book[i]; //static the numbers of every word in words.
        }
        int words_num = words.size();
        int len = words[0].size();
        for(int i=0; i<s.size()-words_num*len+1; ++i){
            unordered_map<string, int> seen;//static the nums of each word have been seen.
            int j = 0;
            //there are 2 cases that is not satisfied: 1. not find in book; 2.the word in seen more than in book.
            for( ; j<words_num; ++j){
                string word = s.substr(i + j*len, len);
                if(book.find(word) == book.end()){
                    break;
                } else {
                    ++seen[word];
                    if(seen[word] > book[word]) break;  
                }
            }
            if(j == words_num) ret.push_back(i);
        }
        return ret;
    }
};

void print(vector<int> ret){
    for(auto i : ret) cout << i << " ";
    cout << "---" << endl;
}

int main(){
    freopen("30test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    //cout << INT_MIN << " " << INT_MAX << endl;
    //cout << LLONG_MIN << " " << LLONG_MAX << endl;
    for(int i=0; i<total; ++i){
        string s;
        int size;
        vector<string> words;
        cin >> s;
        cin >> size;
        for(int j=0; j<size; ++j){
            string c;
            cin >> c;
            words.push_back(c);
        }
        auto ret = Sol.findSubstring(s, words);
        print(ret);
    }
}



