#剑指offer
--------

## 第二章
#### 二维数组查找问题
* 选择右上角的节点作为参考点，每次和target比较，会删除一行或者一列
* 主要是选择合适的参考点，利用夹逼法进行范围的缩小

#### 重建二叉树
给定二叉树的前序和中序遍历，求构建完整的二叉树

前序遍历确定根节点，再拿到中序遍历里面，确定左右子树； 对以上程序递归调用。

#### 位运算
求一个数转化为二进制，其中1的个数

观察得到，数n-1,会将末尾的1变为0，后面被取反，如 10100 减1 10011，这两个数相与，会得到一个计数，
统计这种操作进行了多少次即可。

拓展：求m,n二进制数中的不同的个数，方法，先异或，再统计1的个数
#### 链表
* 有时候需要先遍历得到个数再处理
* 提前询问是否可以修改链表的结构
* 提前考虑并处理特殊情况，如链表为空等
* 删除的时候，有没有可能是head,所以很有一个dummy指针的必要
* 反向遍历链表是，可以和stack结合

## 第三章

#### 数值的整数次方
模拟pow的预算，double pow(double base, int exp), 要考虑base=0, exp<0的情况，同时exp<0的情况，指数的运算可以使用优化，分exp奇数偶数计算一半即可。
位运算的使用：exp << 1, exp & 0x1(判断奇偶性)

```cpp
	class Solution {
	public:
	double myPow(double x, int n){
		if(n == 0) return 1;	
        if(n < 0 && n != INT_MIN){        
            n = -n;           
            x = 1/x;            
        }      
        	return n & 0x1 ? x*myPow(x*x, n>>1) : myPow(x*x, n>>1); 
        }
	};
```

#### 打印1到最大的n位数
重点是要考虑到大数的情况，LL也保存不下的那种 

1. 用string保存，模拟加法，同时注意0123这样的要去除前导0
2. 回溯法，即求n个数字的全排列

#### O(1)时间删除链表的一个节点
给定的输入时head ptr 和 delete_node ptr

既然给的是ptr,我们可以直接把delete_node->next 的val 赋值给delete_node,再进行删除。
同时需要考虑是尾节点的情况，这时候必须要全部遍历一遍了。

#### 求链表倒数k个节点
双指针

求链表的中间节点：slow和fast指针，fast是slow的两倍，fast到尾巴时候，slow到中间

判断是否有环：一个走一步，一个走两步，如果有环的话，肯定会相遇

#### 树B是否是树A的子树
两个递归函数，

1.先查找root节点是否相同，相同的话再检测left，right subtree（用第二个递归函数），不同的话，递归的检测A->left和A->right是否包含B

2.递归的边界条件是：B为NULL，TRUE， B!=NULL && A==NULL, false,   B->val != A->val false； 然后再递归调用该函数，使其左右子树都是相同的。

## 第四章

#### 二叉树的镜像
其实就是不断的交换该二叉树的左右子树，递归

边界条件是当前节点为NULL， return； 左右子树都为0，return
然后递归寻找左右子树。  

#### 包含min函数的栈
题目需要设计一种新的数据结构，可以保持stack的特性，同时在O(1)的时间内返回stack中的min,
这题的关键是添加一个辅助stack，这个stack的top在进行push操作时，push的当前所有元素的最小值，
所以从0开始建立辅助stack，top一定都是最小值。

#### 判断stack的压入和弹出序列是不是同一个过程
建立一个辅助stack，重点在于看pop序列，如果下一个pop是stack.top,则直接弹出，否则的话，继续压栈直到找到这个元素（没找到为false）

#### 层次遍历二叉树
deque模型，先root进入queue

```cpp
	while(queue){
		visit front = queue.front;
		queue.pop_front();
		if(front->left) queue.push(left);
		if(front->right)queue.push(right);
	}
```

#### BST的后序遍历是否合法
递归，先找root节点，判断；递归处理左右子树。
传递参数（vector<int> sequence, int length）, length 指代的是子树的长度

#### 二叉树中的和是target的path
回溯法，path保存路径，cur_sum和target比较，paths保存全路径，判断在到达叶子节点的时候，是否满足target，如果不是leaf，不断的添加左右孩子节点。



