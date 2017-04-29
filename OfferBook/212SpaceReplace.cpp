/* Problem: 将空格替换为%20，原字符数组足够长，够替代
 * Solution: 向统计长度，确定最大需要的长度，从后向前替换
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param str: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char str[], int length) {
        // Write your code here
        int space_num = 0;
        for(int i=0; i<length; ++i){
            if(str[i] == ' ')space_num++;
        }
        int new_length = length + 2*space_num;
        int j = new_length-1;
        for(int i=length-1; i>=0; --i){
            if(str[i] == ' '){
                str[j] = '0';
                str[j-1] = '2';
                str[j-2] = '%';
                j -= 3;
            } else {
                str[j--] = str[i];
            }
        }
        return new_length;
    }
};  
