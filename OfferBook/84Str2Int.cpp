/* string tranlate to int
 * Solution: 注意对不同输入的处理，前面有空格，+-符号，后面空格，溢出
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

    /**
     * @param str: A string
     * @return An integer
     */ 
    int atoi(string str) {
        long long ret(0);
        int size = str.size();
        if(size == 0) return 0;
        int index = 0;
        while(index < size && str[index] == ' ') ++index;
        if(index >= size) return 0; //there are all spaces;
        //cout << index << endl;
        
        int last = size-1;
        while(last >=0 && (str[last]>'9' || str[last]<'0')) --last;
        //cout << last << endl;
        if(str[last] == '0' && last-1 >=0 && str[last-1] == '.'){
            last = last-2;
        }        
        int sig = 1;
        if(str[index] == '+'){
            sig = 1;
        } else if(str[index] == '-'){
            sig = -1;
            if(last - index > 13) return INT_MIN;
        } else if('0' <= str[index] && str[index] <= '9'){
            ret = str[index] - '0';
            sig = 1;
        } else {
            return 0;
        }
        ++index;
        if(last-index > 13) return INT_MAX;
        for(; index <=last && '0' <= str[index] && str[index] <= '9'; ++index){
            ret = ret*10 + (str[index]-'0');
        }

        ret *= sig;
        if(ret < INT_MIN) ret = INT_MIN;
        if(ret > INT_MAX) ret = INT_MAX;
        return ret;
        //if(index > last) return ret; 
        //else return 0;

    }
};

int main(){
    string str("    52lintcode   ");
    Solution Sol;
    int ret = Sol.atoi(str);
    cout << ret << endl;
}
