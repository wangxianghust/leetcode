/*翻转字符串中的每个单词，只是翻转单词
 *Solution: 就按顺序一个一个翻转吧
 */

#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords_(string s) {
        // write your code here
        reverse(s.begin(), s.end());
        int index = 0;
        for(int i=0; i<s.length(); ++i){
            if(s[i] != ' '){   //find first word,then this can find next new word because every loop we handle one string.
                if(index != 0) s[index++] = ' '; //this is not front space.
                int j = i; //from word begin to find word end
                while(j<s.length() && s[j] != ' ') s[index++] = s[j++];
                //revese(first, last) ---> [first, last)
                reverse(s.begin() + index - (j-i), s.begin()+index);
                i = j;//s[j] == ' ', then next is not ' ', denote a new word.
            }
        }
        s.resize(index); //cause index-1+1
        return s;
    }

    string reverseWords(string s){
        istringstream in(s);
        string temp;
        in >> s; //get first string, then there will be a " " after a string.
        while(in >> temp) s = temp + " " + s;
        return s;
    }
};
