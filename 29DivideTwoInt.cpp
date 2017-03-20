#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
       if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
       int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
       long long divd = labs(dividend);
       long long divs = labs(divisor);
       long long ret = 0;
       while(divd >= divs){
           long long tmp = divs;
           long long shift = 1;
           while(divd >= (tmp << 1)){
               tmp <<= 1;
               shift <<= 1;
           }
           divd -= tmp;
           ret += shift;
       }
       return (sign == 1) ? ret : -ret;
    }
};

int main(){
    freopen("29test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    //cout << INT_MIN << " " << INT_MAX << endl;
    //cout << LLONG_MIN << " " << LLONG_MAX << endl;
    for(int i=0; i<total; ++i){
        int dividend, divisor;
        cin >> dividend >> divisor;
        cout << Sol.divide(dividend, divisor) << endl;
    }
}


