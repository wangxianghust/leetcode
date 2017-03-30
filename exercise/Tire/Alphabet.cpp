/*实现一种数据结构可以添加单词和进行查询，查询的时候.可以对任意的char进行匹配
 */

#include <iostream>
#include <vector>

using namespace std;

struct TireNode{
    bool is_leaf;
    TireNode* children[26];
    TireNode(){
        is_leaf = false;
        for(int i=0; i<26; ++i){
            children[i] = nullptr;
        }
    }
};

class Dictionaty{
    public:
        Dictionaty(){ root = new TireNode(); }
        
        void insert(string word){
            TireNode* cur = root;
            for(int i=0; i<word.size(); ++i){
                int index = word[i] - 'a';
                if(cur->children[index] == nullptr){
                    cur->children[index] = new TireNode();
                }
                cur = cur->children[index];
            }
            cur->is_leaf = true;
        }

        bool search(string word){
            int size = word.size();
            return search(word, size, 0, root);
        }

        bool search(string word, int size, int pos, TireNode* cur){
            if(pos == size) return cur->is_leaf;
            if(cur == nullptr) return false;
            if(word[pos] == '.'){
                for(int i=0; i<26; ++i){
                    if(cur->children[i]){
                        if(search(word, size, pos+1, cur->children[i])) return true;
                    }
                }
            } else {
                int index = word[pos] - 'a';
                if(cur->children[index] == nullptr){
                    return false;
                } else {
                    return search(word, size, pos+1, cur->children[index]);
                }
            }
            return false;
        }
    private:
        TireNode* root;
};

int main(){
    Dictionaty tree;
    tree.insert("hello");
    tree.insert("he");
    tree.insert("world");
    cout << tree.search("hea") << endl;
    cout << tree.search("he") << endl;
    cout << tree.search("...lo") << endl;
    cout << tree.search("...ld") << endl;
    cout << tree.search(".o") << endl;
}
