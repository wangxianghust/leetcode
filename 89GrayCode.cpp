/*Gray Code: 二进制编码，相邻两位只有one bit一样，给出位数n,求从0开始的序列
 * 解法：找规律，每次新加一位编码，如n-1到n,则是2^n加上之前数列的逆序和
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return vector<int>{0};
        vector<int> ret{0,1};     
        for(int i=1; i<n; ++i){
            int base = pow(2,i);
            int len = ret.size();
            for(int j=len-1; j>= 0; --j){
                ret.push_back(base+ret[j]);
            }
        }
        return ret;
    }
};

void print(vector<int> ret){
    for(auto i : ret) cout << i << " ";
    cout << endl;
}
int main(){
    freopen("89test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        int n; cin >> n;
        auto ret = Sol.grayCode(n);
        print(ret);
    }
}
