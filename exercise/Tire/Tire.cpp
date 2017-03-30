/*Tire：字典查询树的实现，Tire是典型的空间换取查询时间
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TireNode{
public:
    bool is_leaf;
    unordered_map<char, TireNode*> children;
    TireNode(): is_leaf(false){}
};

class Tire{
    public:
        Tire(){ root = new TireNode(); }
        //insert a word to tire
        void insert(string word){
            TireNode* r = root;
            for(int i=0; i<word.size(); ++i){
                if(r->children.find(word[i]) == r->children.end()){
                    r->children[word[i]] = new TireNode();
                }
                r = r->children[word[i]];
            }
            r->is_leaf = true;
        }

        //search a word
        bool search(string word){
            TireNode* r = root;
            for(int i=0; i<word.size(); ++i){
                if(r->children.find(word[i]) == r->children.end())return false;
                r = r->children[word[i]];
            }
            return r->is_leaf;
        }
    private:
        TireNode *root;
};

int main(){
    Tire tree;
    tree.insert("hello");
    tree.insert("he");
    tree.insert("world");
    cout << tree.search("hea") << endl;
    cout << tree.search("he") << endl;
}
