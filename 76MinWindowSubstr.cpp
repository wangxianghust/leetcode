/*问题：给定两个字符串S，T。求S的最小子串M，M包含T中所有的字符（个数也要等于或超过）
 * 解决：使用map存储字符出现及其出现的个数（优化：由于都是字符，使用int a[256]就可以保存
 * ASCII下的所有字符及拓展字符），同时记录T中的每一个字符为一个条件，用count衡量。
 * 使用双指针，先找到一个符合条件的，然后移动start指针
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string ret;
        if(s.empty() || t.empty()) return ret; 
        int t_map[256];
        for(int i=0; i<256; ++i) t_map[i] = 0;
        for(int i=0; i<t.size(); ++i) t_map[t[i]]++;
        int counter = t.size(); //the number of constraints by string t.
        int len = INT_MAX; //to mark the windows len
        int head = 0; //mark the head
        int start(0), end(0);
        while(end < s.size()){
            if(t_map[s[end++]]-- > 0) counter--; //find one constraint
            while(counter == 0){
                if(len > end-start) {
                    len = end-start;
                    head = start;
                }
                if(t_map[s[start++]]++ == 0) counter++; //why == 0 : cause if t_map[s[start]] == 0, then this char is one constraint. counter++ make while invalid.
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};

int main(){
    //AC
}
