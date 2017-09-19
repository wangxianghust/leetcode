/*
 * 大整数的加法，即string 加法
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string ret = "";
        while(i >= 0 || j >= 0 || carry == 1){
            int sum = 0;
            int left(0), right(0);
            if(i >= 0){
                left = num1[i] - '0';
                --i;
            }
            if(j >= 0){
                right = num2[j] - '0';
                --j;
            }
            sum = left + right + carry;
            carry = sum/10;
            sum = sum%10;
            ret += to_string(sum);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
