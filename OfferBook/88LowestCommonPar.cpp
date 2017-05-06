/*给定二叉树，找到两个节点的公共祖先节点
 * Solution: 先从root找到到达节点的path,再从root出发，求两个单链表开始分开的点就是
 * lowest common parent
 */

#include <iostream>
#include <vector>

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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        vector<TreeNode*> A_set, B_set;
        pathSet(root, A, A_set);
        pathSet(root, B, B_set);
        for(auto i : A_set) cout << i->val << " ";
        cout << endl;
        for(auto i : B_set) cout << i->val << " ";
        int i=0;
        while(i<A_set.size() && i<B_set.size() && A_set[i] == B_set[i]) ++i;
        if(i == A_set.size()) return A_set.back();
        if(i == B_set.size()) return B_set.back();
        
        return A_set[i-1];
    }
private:
    //This method has logic error, cause even if we get the true path, we will run too, wrong.
    /*
    void pathSet(TreeNode* root, TreeNode* to_find, vector<TreeNode*> &path){
        if(root == NULL) return;
        if(root == to_find){
            path.push_back(root);
            return;
        }
        path.push_back(root);
        if(root->left) pathSet(root->left, to_find, path);
        if(root->right) pathSet(root->right, to_find, path);
        //path.pop_back();  //If want this code right, we should pop_back, cause only when we put the wrong node, we can do it.
    }
    */

    //why follow is ok, but top is not.
    bool pathSet(TreeNode* root, TreeNode* to_find, vector<TreeNode*> &path){
        if(root == NULL) return false;
        if(root == to_find){
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if(pathSet(root->left, to_find, path)) return true;
        if(pathSet(root->right, to_find, path)) return true;
        path.pop_back();
        return false;
    }
}; 

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* r = new TreeNode(2);
    TreeNode* rr = new TreeNode(3);
    TreeNode* rrr = new TreeNode(4);
    TreeNode* rrrr = new TreeNode(5);
    root->right = rr;
    root->left = r;
    //rr->right = rrr;
    //rrr->right = rrrr;
    Solution Sol;
    cout << Sol.lowestCommonAncestor(root, rr, r)->val << endl;
}
