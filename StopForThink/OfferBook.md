#剑指offer
--------

## 第二章
#### 二维数组查找问题
* 选择右上角的节点作为参考点，每次和target比较，会删除一行或者一列
* 主要是选择合适的参考点，利用夹逼法进行范围的缩小

#### 重建二叉树
给定二叉树的前序和中序遍历，求构建完整的二叉树

前序遍历确定根节点，再拿到中序遍历里面，确定左右子树； 对以上程序递归调用。重点是确定递归函数是什么样的？

递归函数调用的是子树的PreOrder和InOrder序列,注意的是如果是一个节点要return root， 在left_tree length > 0 方可构建左子树，同理对待右子树。
```cpp
TreeNode* construct(vector<int> &preorder, int pre_s, int pre_e, vector<int> &inorder, int in_s, int in_e)
```
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

#### 13.O(1)时间删除链表的一个节点
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

#### 20.二叉树的镜像
其实就是不断的交换该二叉树的左右子树，递归

边界条件是当前节点为NULL， return； 左右子树都为0，return
然后递归寻找左右子树。  

#### 21.包含min函数的栈
题目需要设计一种新的数据结构，可以保持stack的特性，同时在O(1)的时间内返回stack中的min,
这题的关键是添加一个辅助stack，这个stack的top在进行push操作时，push的当前所有元素的最小值，
所以从0开始建立辅助stack，top一定都是最小值。

#### 22.判断stack的压入和弹出序列是不是同一个过程
建立一个辅助stack，重点在于看pop序列，如果下一个pop是stack.top,则直接弹出，否则的话，继续压栈直到找到这个元素（没找到为false）

#### 23.层次遍历二叉树
deque模型，先root进入queue

```cpp
	while(queue){
		visit front = queue.front;
		queue.pop_front();
		if(front->left) queue.push(left);
		if(front->right)queue.push(right);
	}
```

#### 24.BST的后序遍历是否合法
递归，先找root节点，判断；递归处理左右子树。
传递参数（vector<int> sequence, int length）, length 指代的是子树的长度

#### 25.二叉树中的和是target的path
回溯法，path保存路径，cur_sum和target比较，paths保存全路径，判断在到达叶子节点的时候，是否满足target，如果不是leaf，不断的添加左右孩子节点。

#### 27.二叉搜索树转为双向链表
中序遍历，递归，将原BST的left当做prev指针，right当做next指针。对于一个BST的处理方法是，root->left = left-subtree中的right-most节点，root->right = right-subtree中的left-most节点。
注意判断left是否为null的情况，递归调用即可。

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

## 第六章
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


#### 40.数组中只出现一次的数字
一个int数组中，除了两个数字a,b之外，其他数字都出现了两次，求着两个数字，要求时间复杂度O(n)，空间复杂度O(1).

从简单的角度，如果只有一个数字怎么求？每个数字进行异或，由于同一个数字异或得到的结果是0，所以最后的结果是就是那个单个的数字。

那两个怎么求，还是先异或，然后得到一个数字结果ret,找到ret为1的最低位m，这个位表示了a，b不同的一位，然后依次检测各个数字的第m位，为1的分为一组，为0的分为一组，这种分组策略可以把两个数字分开（显然），同时相同的数字必然在一个组（显然）。
然后对得到的两个分组进行一个不同数字求解的方法。

#### 41.和为s的连续整数序列
eg, 求和为15的 1+2+3+4+5 = 4+5+6 = 7+8 = 15
连续整数序列，要利用该序列是已经排序的，要利用这个结果

用small和big两个指针，small=1; big=2; 先不断的增加big,如果big>sum,再while的增大small的index,得到sum后输出

#### 42.翻转单词顺序
翻转整个句子的顺序，但是单个单词的顺序不用翻转。如“I am a student.” 变换为 “student. a am I”

思路：先整体翻转，再单独每个单词，只需要一个string的reverse函数即可，翻转单词时候，注意end是space，string的end是‘\0'

#### 43.n个骰子的点数

1. 递归，递归求出所有的和，然后计算 sum/total,即可得出n个骰子点数和的概率
2. 动态规划，可以看出 f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6), 因此只需要知道前6个状态即可。

#### 44. 扑克牌的顺序
问题是求5张牌是不是连续的，大小王0可以替换成任何的牌

先排序，再统计0的个数，再统计相邻数字间的空缺数，如果空缺的总数小于等于0的个数，可以，or不可以。

#### 45.圆圈中最后剩下的数字
0,1...n-1这n个数字排成一个圆圈，从数字0开始从圆圈里删除第m个数字，求圆圈里剩下的最后一个数字。

1. 很显然的使用一个圆环链表就可以，不过如果不能使用stl,需要自己构圆环链表，就是走到end的时候，再返回到begin，核心代码如下：
	```cpp
	while(numbers.size() > 1){
		for(int i=0; i<m; ++i){
			current++;
			if(current == numbers.end())
				current = numbers.begin();
		}
		list<int>::iterator next = ++current;
		if(next == numbers.end())
			next = numbers.begin();
		--current;
		numbers.erease(current);
		current = next;
	}
	```
	
2. 数学分析，找出了一个递推公式
	n=1, f(n,m) = 0;	n>1, f(n,m) = (f(n-1, m) + m) % n;
	使用循环的核心代码
	```cpp
	int last = 0；
	for（int i=0; i <= n; ++i）{
		last = (last+m) % i;
	}
	```

#### 46.求1+2+...+n
题目要求数列和，同时不能使用for,while循环等条件

1. 可以使用构造函数

#### 47.不用加减乘除的加法
使用位运算，先计算a^b,第一步计算加法，不计算进位；在计算a&b << 1, 计算进位；递归调用相加。
	```cpp
	int Add(int num1, int num2){
		int sum, carry;
		do{
			sum = sum1 ^ sum2;
			carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0)		
		return num1;
	}
	```
	
#### 48.不能继承的类
C++ 没有不能继承的关键字，先要求提供一个不能继承的类。
将constructor 和 destructor设置为private，然后public下new 和 delete这个类。

## 第七章
#### 49.实现atoi
这题的含义是需要考虑到各个不同的输入情况
如+ -开始的情况，正负溢出的情况，字符串是否为空的情况，等，再进行转化的处理。

#### 50.树中两个节点的最低公共祖先
1. 如果是BST
进行大小查找，比两个数大的话，向右，反之，向左；直到找到第一个介于两个数之间的节点。

2. 普通的树
是否有指向父节点的指针，如果有，转化为两个链表找第一个公共节点
如果没有，那么从root遍历，找到达目的节点的path,在找到从root开始的两条path最后一个相同的元素就是。

其中从root遍历找target node,是一个递归过程；

## 第八章
#### 51. 数组中重复的数字
长度为n的数组，数字都在0~n-1,求重复的数字
可以hash,不过需要O(n)的空间，怎么办？注意每个数字i必须在index为i-1的位置上，那么检测每个A[i]（0<A[i]<n-1）,将其和A[A[i]]比较，不同就交换，将A[i]放在合适的位置上。再对A[i]进行这样的处理，直到找到一个重复的数字。

#### 52.构建乘积数组
给定A[n], 求B[n], 其中 B[i] = A[0]*A[1]...A[i-1] * A[i+1] * ... A[n],要求不能使用除法

暴力求解的方法是O(n^2)，不过明显可以使用动态规划，

用before[i]表示i前面数字的乘积，则before[i+1] = before[i] * A[i];

用after[i]表示从末尾开始的乘积，则after[i-1] = after[i] * A[i];

则 ret[i] = before[i] * after[i]; 时间复杂度O(n),空间复杂度O(n).

#### 53.正则表达式匹配
关于. * 的匹配，递归，重点考虑的a* 的情况，将 a\*看成一个字符来处理
	```cpp
	bool match(char* str, char* pattern){
		//border case...
		//mach case
		if(*str == '\0' && *pattern == '\0) return true;
		if(*str != '\0' && *pattern == '\0) return false;
		if(*(pattern+1) == '*'){
			if(*pattern == '.' || *pattern == *str){
			//three case, a* match nothing, a* match a 
			//and stay state, a* match a and go next state.
				return match(str, pattern+2)
				|| match(str+1, pattern+2)
				|| match(str+1, pattern);
			} else {
				return match(str, pattern+2);
			}
		}
		if(*pattern == '.' || *pattern == *str){
			return match(str+1, pattern+1);
		}
	}
	```
	
#### 54.表示数值的字符串
要考虑的正负号，指数，小数等情况，关键是剥离出几个模块，
一个是scanDigits用于扫描是不是数字，一个是isExponential(string &str),判断e或E出现之后的字符是否合法。

#### 55.字符流中第一个不重复的字符
可以使用stl的unordered_map进行hash,但还是自己构建一个hash表吧，int occurence[256], 初始化为-1，重复出现赋值为-2，出现一次保存其index。最后从0开始扫描，得到第一个 >= 0的数值即可。

#### 56.链表中环的入口节点
一个链表中包含环，求出环的入口节点
这题的解法很多，先列举几个

1. 增加空间：一次访问各个节点，如果一个节点第一次被再访问，那么就是入口节点，set<node> nodes, 不断的向nodes中添加节点，直到遇到一个重复的
2. O(n)，但是破坏链表，用pre,cur两个指针遍历，一旦node被visited,将node->next = null, 继续直到访问到最后一个节点就是环的入口节点。
3. tricky
	a. 首先判断有没有环，然后找到环中的一个节点，方法：
	slow 和 fast两个指针，slow每次一步，fast每次两步，如果有环，两个指针必定相遇，且相遇节点在环内；
	b. 假设环的长度是y，则让p1先走y步，然后p2指向head指针，p1,p2一起走，第一次的相遇节点就是环的入口节点。理由是，可以想象非圈节点个数是x,总个数是n。
	
#### 57.删除链表中的重复节点
链表的简单操作，注意设置一个dummy节点指向head节点，为了防止head也是重复的节点需要被删除。

#### 58.二叉树的下一个节点
求在中序遍历情况下，给定一个节点，求这个节点的下一个节点。（题设给了每个节点的parent指针）

解决的方案是模拟中序遍历的下一个节点过程，分为三个方向：

a. 节点有right child, 寻找right child中的left--most node.
b. 节点无right child && node == parent.left,则parent是next
c. 节点无right child && node == parent.right, 则向上回溯，直到找到一个节点满足 node == parent.left


#### 59.对称的二叉树
判断一棵树是不是镜像对称的

简单的递归，入口判断条件是，left,right为NULL的各种判断，以及节点value是否相等，然后再递归判断左右子树是否是对称的。

#### 60.层序遍历
用queue保存即可，每次访问一个节点之后，pop,每次访问第n层节点的时候，在上一步先统计出该层节点的个数（即当时queue.size();

#### 61.zig-zag层序遍历
可以使用deque
可以双stack

#### 62.序列化二叉树
序列化：就是简单的前序遍历

反序列化：同样的，对于有value的节点，先构造该节点并默认节点的左右子树为NULL，然后递归构造左右子树。反序列化的code如下：
进位；递归调用相加。
	```cpp
	void Deserialize(BinaryTreeNode** pRoot, istream& stream){
		int number;
		if(ReadStream(stream, &number)){
			*pRoot = new BinaryTreeNode();
			(*pRoot)->m_nValue = number;
			(*pRoot)->m_left = NULL;
			(*pRoot)->m_right = NULL;
			Deserialize(& ((*pRoot)->m_left), stream);
			Deserialize(& ((*pRoot)->m_right), stream);
		}
	}
	```
	
#### 63.BST的第k个节点
InOrder travel就是按顺序排列的，所以按照InOrder travel到第k个节点即可，计数模块在原来print(root->val)部分；
进位；递归调用相加。
	```cpp
	Node* KNode(Node* root, int &k){
		target = NULL;
		if(root->left) target = KNode(root->left, k);
		if(target == NULL) {
			if(k == 1) target = root;
			k--;
		} 
		if(root->right) target = KNode(root->right, k);
	}
	```