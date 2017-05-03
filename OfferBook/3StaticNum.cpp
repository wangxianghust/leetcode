/* 计算数字k在0~n中出现的次数，k可能是0~9之间的一个值
 * Solution: k = 0的情况单独讨论，其他的值使用 ret = first_digit_num + other_digit_num + recur_num;
 * eg. 2345, 第一次考虑 346~2345， 第二次考虑 46~345...
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        string str = to_string(n);
        return digitCounts(k, str);
    }

private:
    int digitCounts(int k, string str){
        if(str.empty() || str[0] < '0' || str[0] > '9') return 0;
        int first_digit = str[0] - '0';
        int first_digit_num(0), other_digit_num(0), recur_num(0);
        int len = str.size();
        //First we should consider when there is only one ele : cause other_digit_num use len-2, when len=1 we consider it specially.
        if(len == 1 && first_digit < k) return 0;
        if(len == 1 && first_digit >= k) return 1;
        //calculate the first_digit_num, which means there must be first digit.
        if(k != 0){
            if(first_digit > k) {
                first_digit_num = pow(10, len-1);
            } else if(first_digit == k){
                first_digit_num = stoi(str.substr(1)) + 1;  //ignore the high digit, the resume add 1.
            } else {
                first_digit_num = 0;
            }
        } else {
            first_digit_num = 0;
        }
        //calculate other digit num
        other_digit_num = (str[0]-'0') * pow(10, len-2) * (len-1);

        //calculate the recur_num
        recur_num = digitCounts(k, str.substr(1));
        return first_digit_num + other_digit_num + recur_num;
    }
};
