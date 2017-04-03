/*问题：求两个二进制string的和
 *方法：正常求解判断几种情况
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int a_size = a.size();
        int b_size = b.size();
        if(a_size < b_size) swap(a, b);  //a.size() >= b.size()
        int c(0);
        int sum(0);
        int size_max = max(a_size, b_size);
        int size_min = min(a_size, b_size);
        string ret(size_max+1, '1');
        int i=size_min-1;
        int j= size_max+1-1;
        for( ; i>=0; --i){
            sum = a[i] - '0' + b[i] - '0' + c;
            if(sum >= 2) c=1;
            if(sum == 0 || sum == 2) ret[j--] = 0;
        }

        for(i=size_max-size_min-1; i>=0; --i ){
            sum = a[i] - '0' + c;
            if(sum == 2) c=1;
            if(sum == 0 || sum == 2) ret[j--] = 0;
        }
        return c==1 ? ret : ret.substr(1); 
    }
};

int main(){
    //AC
    string a("12345");
    cout << "test " << a.substr(1);
    freopen("67test.txt" , "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        string a,b;
        cin >> a >> b;
        cout << Sol.addBinary(a, b) << endl;
    }
}
