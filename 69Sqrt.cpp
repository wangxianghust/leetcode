/*模拟平方根的计算
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    //Use Netwon function
    int mySqrt(int x){
        double ret = x;
        double diff = 1e-6;
        while(fabs(ret*ret - x) > diff){
            ret = (ret + x/ret)/2;
        }
        return ret;
    }

    int mySqrt_(int x) {
        int low = 0;
        int high = x;
        int mid;
        while(low <= high){
            mid = (high-low)/2 +low;
            if(mid > x/mid)high = mid-1;
            else low=mid+1;
        }
        return high;
    }
};

int main(){
    freopen("69test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        int x; cin >> x;
        cout << Sol.mySqrt(x) << endl;
    }
}
