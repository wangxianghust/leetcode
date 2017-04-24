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

## 第五章
#### 32.从1到n个整数中，求1出现的次数

1. 对于每一个数字，求其中的1的个数（通过不断的mod和/）,复杂度n*lgn,太高不考虑
2. 对数字的规律进行观察，从高位到低位，不断的计算每个十进制位中1的数量，递归调用（技巧：将数字转化为string, f方便处理），注意是统计1的个数，不是排列组合。公式：
	a. 先求最高位中1的数量：	
	当1出现在高位时，去掉最高为加1（如123，共有100\~123，计为24个），当最高位大于1时，为pow(10,len-1), 如（213，共有100\~199，最高位共计100个1）
	b. 除最高位剩下位置中1的个数： 
	```cpp
	FirstData*(len-1)*pow(10,len-2)
	```
	解释：如3456（计算非最高位中1的数量），FirstData=3,含义是可以分解为三段，457~1456， 1457~2456，2457~3456；len-1的含义是除去最高位，剩下的位数可以选择是1，pow(10,len-2)的含义是，除去最高位和选中的那位1，剩下的可以任意排列的可能。
	
采用递归调用，计算每个最高的个数
TotalNum = NumFirstDigital + NumOtherDigital + NumRecursive;

#### 33.把数组排成最小的数字
eg. {1, 15, 156} --> ret = 115156
Solution：使用string保存

1. 使用回溯法得到数组拼接的所有结果n!,然后遍历一遍得到最小值，复杂度是 n!无法接受
2. 定义一个新的compare函数，比较ab和ba,如果ab < ba， 则 a<b;
如果 ab > ba, 则a > b; 如果 ab = ba, 则a = b;核心代码如下：
	```cpp
	struct compare{
		bool opreator() (const string &a, const string& b){
			string s1 = a+b;
			string s2 = b+a;
			return s1 < s2;
		}
	}	
	...
	sort(array, array+size, compare());
	for(string i : array) ret += i;
	```
	证明：使用反证法，假设a<b(ab < ba),存在一个最小数使得b在a前面
	其实是两种情况
		1. （ab..., ...ab）简单易得；
		2. （a...b, 与 b...a）,表示成ayb和bya，分别假设出a,b,c的位数即可证明。
		
#### 34.丑数
丑数指的是只能被2，3，5整除的数字，求第1500个丑数

1. 写一个丑数的判断方法，然后从1开始不停的判断，直到得到了1500个丑数
2. 从生成丑数的角度进行考虑，对于已经得到的前n个丑数，求n+1个时候，我们使用每个元素分别乘2,3,5，分别找到每个大于当前最大元素的M2,M3,M5，然后求取上述三个数的最小值就是next 丑数。 只是多使用了空间保存了前n个丑数。

#### 35.第一个只出现一次的字符
查找次数，重复等相关的需要想到hash map，如unordered_map(基于hash实现)，当然也可以自己定义hash函数，由于字符，用256个可以保存 
	```cpp
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	...
	hashTable[*(pHashKey)]++;
	```
	
#### 36. 查找数组中的逆序对
和merge sort很像，每次比较后，我们记录顺序，防止重复计算。
assume left_arr and right_arr are sorted, 

we use the pointer l from end of left_arr and r from end of right_arr, 

if left_arr[l] > right_arr[r], the inveser_pairs come, and the number is num = r - right_arr.start_index + 1, AND we should save the ordered array.

#### 37.两个链表的第一个公共节点
Assume list A length is m, list B is n. assume m > n.

let A go (m-n) step, then let A and B go together, find first same node is the first same node.

观察两个list交叉后，那么其后面的节点必定都是重合的，所以先让长的节点先走（m-n）,然后两个list一起走，最先遇到的就是第一个公共节点。

#### 38.数字在排序数组中出现的次数
即对于一个排序的数组，使用二分查找法找到一个数字出现的开始位置和结束位置。
eg. 查找开始的位置，A[mid] < target 右半 or A[mid] > target 左半
A[mid] == target, if A[mid-1] == target, 继续左半，直至找到

同理查找结束的位置

#### 39.二叉树的深度
使用递归即可

拓展：判断一棵树是不是平衡树（任意节点的左右子树深度差不超过1）

1. 从root向下，计算root->left, root->right, 比较即可判断root节点的左右子树是否平衡，然后递归判断left-child是不是平衡节点，right-child是不是平衡节点，这个方法有着大量的重复计算

2. 后序遍历，先根据左右节点的深度判断是不是平衡的，并得到当前节点的深度，最后遍历到树的根节点即可判断。