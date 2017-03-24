#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;

        int i=0;
        while(i < str.size() && str[i] == ' ') ++i;
        long long ret = 0;
        int size = str.size();
        if(i >= size) return 0;
        int sign = 1;
        //--i;
        if(str[i] == '+'){
            sign = 1;
        } else if(str[i] == '-') {
            sign = -1;
            if(size - i > 13) return INT_MIN;
        } else if('0' <= str[i] && str[i]<= '9'){
            sign = 1;
            ret = str[i] - '0';
        } else {
            return 0;
        }
        if(size - i > 13) return INT_MAX; //cause long string num, the long long may overflow.
        while(i+1<size&& '0' <= str[++i] && str[i]<= '9'){
            int tmp = str[i] - '0';
            ret = ret*10 + tmp;
        }
        ret = ret * sign;
        if(ret < INT_MIN) return INT_MIN;
        if(ret > INT_MAX) return INT_MAX;
        return ret;
    }
};

int main(){
    freopen("8test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){  //line 8 can not pass now. ???
        string str;
        cin >> str;
        cout << Sol.myAtoi(str) << endl;
    }
}
