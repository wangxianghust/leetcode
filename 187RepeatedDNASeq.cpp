/* 给定一个DNA字符串，即只有A,G,C,T四个元素组成，pattern是连续的10个字符，求出现超过一次的pattern。
 * Solution：1.直观上，使用hash_map进行统计字符串，个数超过1个的即可
 * 
 * 2.将连续10个字符作为key不合理，观察，只有A,G,C,T四个，我们可以编码，2bits即可，那么10个字符只要20bits
 * 可以保存，因此unordered_map<int, int>, key的后20bits表示字符串，value表示出现的次数，一旦发现一个字符串
 * 不是第一次出现就加入ret。
 *
 * 以上的重点是如何设计一个映射函数，将四元素分别映射成1，2，3，4，你不能每次来个字符都用switch吧，不方便，
 * 可以使用diff,每个字符和A的差值映射下，由于差值小于26，用char[26] 即可。
 *
 * 3. 还有一种方法，每个字符用3bits表示，这样10个字符是30bits,还在int的范围内，为什么用3bits呢？因为
 * A 65  G 71  C 67 T 84 模7得到的结果不一样，因此使用 (c << 3) & 0x7 即可表示该字符
 * 其他和上面一样
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s){
        vector<string> ret; 
        int size = s.size();
        if(size < 10) return ret;
        unordered_map<int, int> book; //key is 10characters, value is num.
        char trans[26];
        trans['A' - 'A'] = 0;
        trans['G' - 'A'] = 1;
        trans['C' - 'A'] = 2;
        trans['T' - 'A'] = 3;

        int i(0), t(0);
        while(i < 9) t = (t << 2) | ( ( trans[s[i++]-'A'] ) & 0x3);
        while(i < size){
            t = (t << 2) | ( ( trans[s[i++]-'A'] ) & 0x3);
            int key = t & 0xfffff;
            book[key]++;
            if(book[key] == 2){
                ret.push_back(s.substr(i-10, 10));
            }
        }
        return ret;
    }

    
    vector<string> findRepeatedDnaSequences_(string s) {
        vector<string> ret; 
        int size = s.size();
        if(size < 10) return ret;
        unordered_map<int, int> book; //key is 10characters, value is num.
        int i(0), t(0);
        while(i < 9){
            t = (t << 3) | (s[i] & 0x7); //s[i]%7 并保存到t的后三位中
            ++i;
        }

        while(i<size){
            t = (t << 3) | (s[i++] & 0x7);
            int key = t & 0x3fffffff; //取后30bits是key
            book[key]++;
            if(book[key] == 2){
                //key is second time comes, more than 2 is discarded.
                ret.push_back(s.substr(i-10, 10));
            }
        }
        return ret;
    }
};
