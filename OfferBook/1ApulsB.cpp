/* 不用加法模拟加法，都是32bit的整数
 * Solution:使用位运算，分别计算尾数，和进位位，知道进位位是0，最后得到的数即为结果
 * 其中尾数的计算使用 异或， 进位位使用 与，然后左移1位
 * 如何证明算法肯定会结束？进位位是&运算，每次左移1位，则每次右边的那个位不可能再为1，因此进位位最后肯定为0，最多迭代32次(int 为 32bits)
 */

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int ret(a);
        while(b){
            ret = a^b;  
            int carry = (a&b) << 1;
            b = carry;
            a = ret;
        }
        return ret;
    }
};

int main(){
    int a(5), b(-3);
    //cout << (a&b) << " " << (a^b) << endl;
    bitset<32> _a = a;
    bitset<32> _b = b;
    bitset<32> bit = a&b;
    cout << _a << endl;
    cout << _b << endl;  
    cout << bit << endl;  
}
