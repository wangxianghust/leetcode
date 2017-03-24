/*模拟指数运算
 * 使用二分法即可，对于负指数的处理要注意，尤其是-INT_MIN会溢出的问题
 */
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n){
        if(n == 0) return 1;
        //MUST NOTICE: if n is INT_MIN(-2147483648), then -n is overflow;
        if(n < 0 && n != INT_MIN){
            n = -n;
            x = 1/x;
        }
        //const double MIN = 1e-15;
        //if(fabs(x) < MIN) return 0;
        return n%2 ? x*myPow(x*x, n/2) : myPow(x*x, n/2);
    }
    double myPow_(double x, int n) {
        if(n == 0) return 1;
        if(x == 0 && n > 0) return 0;
        bool flag = (n>0) ? true : false;
        n = abs(n);
        double ret = 1;
        for(int i=0; i<n; ++i){
            ret *= x;
        }
        return flag ? ret : 1/ret;
    }
};

int main(){
    freopen("50test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        double x; cin >> x;
        int n; cin >> n;
        double ret = Sol.myPow(x, n);
        cout << ret << endl;
    }
}
