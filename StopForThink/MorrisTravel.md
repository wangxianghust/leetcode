# MorrisTravel

#### 算法特点
非递归，不用栈，O(1)空间
中间过程会改变二叉树的结构，最后会recovery.

要使用O(1)空间进行遍历，最大的难点在于如何返回到父节点，这里用到了叶子节点中的左右空指针。

#### 算法描述
1. Initialize current as root
2. while current is not NULL
    if current node does not have left child
    	print cur.data
    	Go to right, cur = cur->right
    Else
    	定义r是cur左子树中rightmost节点,令 r->right = cur
    	Go To left child. cur = cur ->left