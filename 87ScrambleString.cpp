/*问题：对于一个string可以使用二叉树进行表示，同时有一种scramble操作，就是交换两个非叶子节点，这样
 * 会形成新的字符串，现在给两个string，判断是不是可以通过scramble操作转换
 * 解决：使用递归来做，但是解空间是指数的，所以要进行合理的剪枝(此处先判断给定两个字符串是否包含相同
 * 数量的字符，可以使用map来做，当然下面使用的是数组，原因，字符可以和自然数下标映射，相当于map)
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        //if(len == 0) return true; //why this will cause segment fault.
        if(len == 1) return s1 == s2;

        //pure
        int count[26];
        memset(count, 0, sizeof(count));
        for(int i=0; i<len; ++i){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0; i<26; ++i){
            if(count[i] != 0) return false;
        }

        for(int i=0; i<len; ++i){
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) 
                && isScramble(s1.substr(i), s2.substr(i)) )return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) 
                && isScramble(s1.substr(i), s2.substr(0,len-i)) ) return true;
        }
        return false;
    }
};

int main(){
    Solution Sol;
    bool ret = Sol.isScramble("great", "rgeat");
    cout << ret << endl;
    string test("great");
    int size = test.length();
    //cout << test.substr(size) << endl;
}
