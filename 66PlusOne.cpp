/*问题：求一个数加1后的结果，含负数，数字使用vector保存
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i=size-1;
        vector<int> ret(digits);
        while(i>=0 && digits[i] == 9) --i;
        if(i<0){
            ret[0] = 1;
            for(int j=1; j<size; ++j)ret[j] = 0;
            ret.push_back(0);
        } else {
            ret[i] += 1;
            for(int j=i+1; j<size; ++j) ret[j] = 0;
        }
        return ret;
    }
};

void print(vector<int> d){
    for(int i:d) cout << i << " ";
    cout << endl;
}

int main(){
    //AC
}
