/*序列化一个Tree，then 反序列化得到原二叉树
 * Solution: 采用先序遍历来序列化，对于NULL使用特殊字符代替
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TreeNode {
public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
};


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string ret;
        ostringstream stream;
        serialize(root, stream);
        ret = stream.str(); //get string from ostringstream
        return ret;       
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        istringstream input;
        input.str(data); //read data to istringstream.
        TreeNode* root = nullptr;
        deserialize(&root, input);
        return root;
    }
private:
    void serialize(TreeNode* root, ostringstream &str){
        if(root == NULL){
            str << "$,";
            return;
        }
        str << root->val << ",";
        serialize(root->left, str);
        serialize(root->right, str);
    }

    void deserialize(TreeNode** root, istringstream& input){
        int num;
        if(readBuffer(input, num)){
            *root = new TreeNode(num);
            //cout << num << endl;
            deserialize( &((*root)->left), input);
            deserialize( &((*root)->right), input);
        }
    }

    bool readBuffer(istringstream& input, int &num){
        if(input.eof()) return false;
        char buffer[32]; //cause int have 32 bits
        buffer[0] = '\0';
        char ch;
        input >> ch;
        int i=0;
        while(!input.eof() && ch != ','){
            buffer[i++] = ch;
            input >> ch;
        }

        bool isNum = false;
        if(i>0 && buffer[0] != '$'){
            num = atoi(buffer);
            isNum = true;
        }
        return isNum;
    }
};

bool isSame(TreeNode* s, TreeNode* t){
    if(s == NULL && t == NULL) return true;
    if(s == NULL || t == NULL) return false;
    if(s->val != t->val) return false;
    return ( isSame(s->left, t->left) && isSame(s->right, t->right) );
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* l = new TreeNode(2);
    TreeNode* r = new TreeNode(3);
    TreeNode* rr = new TreeNode(4);
    root->left = l;
    root->right = r;
    r->right = rr;
    Solution Sol;
    string ret = Sol.serialize(root);
    TreeNode* new_root = Sol.deserialize(ret);
    //cout << new_root->val << endl;
    cout << isSame(root, new_root) << endl;
}
