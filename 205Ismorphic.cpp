/* 判断两个string是不是同构的，同构指的是，egg,add,就是字符的种类数量相同，相应的个数也相同
 * Solution:自己用array模拟一个hash 即可。book存放的是某个char上次出现的位置，一旦上次出现的位置矛盾的话
 * 说明不是同构的。
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_size(s.size()), t_size(t.size());
        if(s_size != t_size) return false;
        vector<int> book1(256,0);
        vector<int> book2(256,0);
        for(int i=0; i<s_size; ++i){
            if(book1[s[i]] != book2[t[i]]) return false;
            book1[s[i]] = i+1;
            book2[t[i]] = i+1;
        }
        return true ;  
    }
};

int main(){
    //AC
}
