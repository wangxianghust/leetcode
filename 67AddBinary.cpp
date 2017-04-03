/*问题：求两个二进制string的和
 *方法：正常求解判断几种情况,就是要注意0和'0'的区别实在太大了，注意书写格式啊。
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
        int ia=size_max-1;
        int ib=size_min-1;
        int j= size_max+1-1;
        for( ; ib>=0; --ia, --ib,--j){
            sum = a[ia] - '0' + b[ib] - '0' + c;
            if(sum >= 2) c=1;
            else c=0;
            if(sum == 0 || sum == 2) ret[j] = '0'; //NOTICE : for string, o is end, '0' is a charater.
            //cout << "test " << ret << endl;
        }

        for(ia=size_max-size_min-1; ia>=0; --ia,--j ){
            sum = a[ia] - '0' + c;
            if(sum == 2) c=1;
            else c=0;
            if(sum == 0 || sum == 2) ret[j] = '0';
        }
        return c==1 ? ret : ret.substr(1); 
    }
};

int main(){
    //AC
    freopen("67test.txt" , "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        string a,b;
        cin >> a >> b;
        cout << Sol.addBinary(a, b) << endl;
    }
}

