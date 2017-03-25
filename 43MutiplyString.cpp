/*问题：求解两个字符串对应数字的乘积
 * 解法：两个for循环，乘法的标准形式，尤其注意进位的数字位置
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.length();
        int size2 = num2.length();
        string sum(size1 + size2, '0');
        for(int i=size1-1; i >= 0; --i){
            int carry = 0;
            for(int j=size2-1; j>=0; --j){
                int tmp = sum[i+j+1] - '0' + (num1[i] - '0')*(num2[j] - '0') + carry;
                sum[i+j+1] = tmp%10 + '0';
                carry = tmp/10;
            }
            sum[i] += carry;
        }
        auto index = sum.find_first_not_of('0');
        if(index != string::npos)return sum.substr(index);
        return "0";
    }
};

int main(){
    freopen("43test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        string num1, num2;
        cin >> num1 >> num2;
        string ret = Sol.multiply(num1, num2);
        cout << ret << endl;
    }
}
