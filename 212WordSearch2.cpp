/* 给定一个dict,和一个2D的字母board，求子board上行走，可以得到dictionary中的哪些单词
 * Solution：将dictionary构造成一个trie树，然后DFS查找
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>

using namespace std;

class TrieNode{
public:
    TrieNode():is_leaf(false){ children = vector<TrieNode*>(26, NULL); }; //26个字母
    bool is_leaf;
    vector<TrieNode*> children;
    //TrieNode():is_leaf(false), children(vector<TrieNode*>(26, NULL)){}; //26个字母
};

class Trie{
    public:
        TrieNode* getRoot(){ return root; }
        Trie(vector<string> &words){
            root = new TrieNode();
            for(string word : words) addWord(word);
        }
        void addWord(string &word){
            TrieNode* r = root;
            for(int i=0; i<(int)word.size(); ++i){
                if(r->children[ word[i]-'a'] == NULL){
                    r->children[ word[i]-'a'] = new TrieNode();
                }
                r = r->children[ word[i]-'a' ];
            }
            r->is_leaf = true;
        }
    private:
        TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        Trie dict(words); 
        TrieNode* root = dict.getRoot();
        set<string> ret;
        vector<string> ret_vec;
        if(board.size() == 0 || board[0].size() == 0) return ret_vec;
        vector<pair<int,int>> direc{ {1,1},{1,-1},{-1,1},{-1,-1} };
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                findWords(board, root, "", ret, 0, 0, direc);
            }
        }
        for(string s : ret) ret_vec.push_back(s);
        return ret_vec;
    }
private:
    void findWords(vector<vector<char> > &board, TrieNode* root, string word, set<string> &ret, int x, int y, vector<pair<int,int>> &direc){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] == 'X') return ; //'X'代表访问过了
        if(root->children[ board[x][y]-'a' ] != NULL){
            char c = board[x][y];
            board[x][y] = 'X';
            root = root->children[ board[x][y]-'a' ];
            word.push_back(c);
            if(root->is_leaf) ret.insert(word);
            for(auto d : direc){
                findWords(board, root, word, ret, x+d.first, y+d.second, direc);
            }
            board[x][y] = c;
        }
    }
};

int main(){
    Solution Sol;

}
