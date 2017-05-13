/* 给一个string和dict,用dictz中的单词切分string，返回所有的结果。
 * Solution：需要求出所有的可能结果，所以要回溯枚举出所有的结果，都进行判定，为了减少计算量，使用map<string, vector<string>>记录一个string
 * 对应的所有可能切分结果。
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        auto str_set = wordBreak(s, words);
        vector<string> ret;
        for(auto &str : str_set){
            string tmp;
            for(auto &i : str) tmp = tmp + i + " ";
            ret.push_back(tmp.substr(0, tmp.size()-1));
        } 
        return ret;
    }
private:
    vector<vector<string> > wordBreak(string &s, unordered_set<string> &wordDict){
        if(book.count(s)) return book[s];
        vector<vector<string>> ret;
        if(wordDict.find(s) != wordDict.end()){
            vector<string> tmp;
            tmp.push_back(s);
            ret.push_back(tmp);
        }
        for(int i=0; i<s.size(); ++i){
            string word = s.substr(0,i+1);
            if(wordDict.find(word) != wordDict.end()){
                string w = s.substr(i+1);
                vector<vector<string> > last = wordBreak(w, wordDict);
                combination(word, last);
                ret.insert(ret.end(), last.begin(), last.end());
            }         
        }
        book[s] = ret;
        return ret;
    }

    void combination(string &word, vector<vector<string>> &last){
        for(auto &str : last){
            str.insert(str.begin(), word);
        }
    }
private:
    unordered_map<string, vector<vector<string>> > book;
};

int main(){
    //AC
}
