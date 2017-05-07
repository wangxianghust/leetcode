/*给定一个升序的数组，求高度平衡的BST
 * Solution:要求高度平衡，那么每次选择数组中间的元素作为root,剩下两边作为左右子树
 * 遍历即可,本质上在构造中序遍历
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return NULL;
        return sortedArrayToBST(nums, 0, size-1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int> &nums, int start, int end){
        TreeNode* root;
        if(start > end) return NULL;
        if(start == end) {
            root = new TreeNode(nums[start]);
            return root;
        }
        int mid = (end-start)/2 + start;
        root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, end);
        return root;
    }
};
