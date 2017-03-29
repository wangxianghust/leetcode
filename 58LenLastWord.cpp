/*问题：求最后一个word的长度，最后一个的定义是非空的字符串，
 * 方法：从最后一个遍历吧,z注意空，尾巴有空格这两种情况即可
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        if(size == 0) return 0;
        int i = size-1;
        int ret = 0;
        while(i >=0 && s[i] == ' ') --i;
        while(i >=0 && s[i--] != ' ') ++ret;
        return ret;
    }
};

int main(){
    Solution Sol;
    vector<string> test{"", "   ", "abc", "a abdx", "a abc abcd   "};
    for(auto item : test){
        cout << Sol.lengthOfLastWord(item) << endl;
    }
}
