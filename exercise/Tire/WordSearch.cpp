/*问题：给出一个字典和一个单词矩阵，找出所有在矩阵和字典中出现的单词（全是小写字母）
 * 矩阵的起点任意，可向上下左右四个方向，矩阵的walk不含有圈
 * 解法：用Trie实现字典，矩阵上单词的查询使用常规DFS即可。
 */

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

struct TrieNode{
    bool is_leaf;
    vector<TrieNode*> children;
    TrieNode(): is_leaf(false) {children = vector<TrieNode*>(ALPHABET, nullptr); }
    static int ALPHABET;
};

int TrieNode::ALPHABET = 26;

class Trie{
    public:
        Trie(){ root = new TrieNode(); }
        void Insert(vector<string> &words);
        void InsertOne(string &word);
        bool Search(string &word);
        TrieNode* GetRoot(){ return root; }

    private: TrieNode* root;
};

void Trie::Insert(vector<string> &words){
    for(string i : words) InsertOne(i);
}

void Trie::InsertOne(string &word){
    TrieNode* cur = root;
    for(int i=0; i<word.size(); ++i){
        int index = word[i] - 'a';
        if(cur->children[index] == nullptr){
            cur->children[index] = new TrieNode();
        }
        cur = cur->children[index];
    }
    cur->is_leaf = true;
}

bool Trie::Search(string &word){
    TrieNode* cur = root;
    for(int i=0; i<word.size(); ++i){
        int index = word[i] - 'a';
        if(cur->children[i] == nullptr){
            return false;
        }
        cur = cur->children[index];
    }
    return cur->is_leaf;
}

class Solution{
    public:
        vector<string> FindFromMatrix(vector<string> &words, vector<vector<char>> &matrix){
            if(matrix.empty() || matrix[0].empty()) return vector<string>();
            //Trie tree;
            Trie* tree = new Trie();
            tree->Insert(words);
            TrieNode* root = tree->GetRoot();
            set<string> ret;
            int row = matrix.size();
            int col = matrix[0].size();
            for(int i=0; i<row; ++i){
                for(int j=0; j<col; ++j){
                    string word;
                    dfs(root, matrix, i, j, ret, word, row, col);
                }
            }
            vector<string> result(ret.begin(), ret.end());
            return result;
        }
    private:
        void dfs(TrieNode* root, vector<vector<char> > &matrix, int i, int j, set<string> &ret, string word, int row, int col){
            if(i<0 || i>=row || j<0 || j>=col || matrix[i][j] == '0') return;
            int index = matrix[i][j] - 'a';
            if(root->children[index]){
                word += matrix[i][j];
                root = root->children[index];
                if(root->is_leaf){
                    ret.insert(word);
                }
                char tmp = matrix[i][j];
                matrix[i][j] = '0';
                dfs(root, matrix, i+1, j, ret, word, row, col);
                dfs(root, matrix, i-1, j, ret, word, row, col);
                dfs(root, matrix, i, j+1, ret, word, row, col);
                dfs(root, matrix, i, j-1, ret, word, row, col);
                matrix[i][j] = tmp;
            }
            return;
        }
};

void print(vector<string> ret){
    for(auto i : ret) cout << i << " ";
    cout << endl;
}

int main(){
    freopen("WordSearch.txt", "r", stdin);
    int total; cin >> total;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<string> words;
        for(int j=0; j<size; ++j){
            string s; cin >> s;
            words.push_back(s);
        }
        //print(words);
        int row, col; cin >> row >> col;
        vector<vector<char> > matrix;
        for(int m=0; m<row; ++m){
            vector<char> line;
            for(int n=0; n<col; ++n){
                char c; cin >> c;
                line.push_back(c);
            }
            matrix.push_back(line);
        }
        //for(auto i:matrix)for(auto j:i) cout << j << " ";
        Solution Sol;
        auto ret = Sol.FindFromMatrix(words, matrix);
        print(ret);
    }
}
