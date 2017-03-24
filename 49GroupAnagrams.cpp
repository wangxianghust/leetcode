#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string> > book;
        vector<vector<string> > ret;
        for(string s : strs){
            //string t(s);
            //sort(t.begin(), t.end());
            string t = bulk_sort(s);
            book[t].insert(s);
        }
        for(auto item : book){
            vector<string> anagram(item.second.begin(), item.second.end());
            ret.push_back(anagram);
        }
        return ret;
    }
//private:
    string bulk_sort(string &str){
        int size = str.size();
        int count[26] = {0};
        for(int i=0; i<size; ++i){
            ++count[str[i] - 'a'];
        }
        int p = 0;
        string ret(size, 'a');
        for(int i=0; i<26; ++i){
            for(int j=0; j<count[i]; ++j){
                ret[p++] += i;
            }
        }
        return ret;
    }
public:
    void print(vector<vector<string> > ret){
        for(auto i : ret){
            for(string j : i)cout << j << " ";
            cout << endl;
        }
        cout << "---" << endl;
    }
};

int main(){
    freopen("49test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<string> strs;
        for(int j=0; j<size; ++j){
            string c; cin >> c;
            strs.push_back(c);
        }
        auto ret = Sol.groupAnagrams(strs);
        Sol.print(ret);
    }
    //For test bulk sort
    string s("acbdaaed");
    string ret = Sol.bulk_sort(s);
    cout << ret << endl;
}
