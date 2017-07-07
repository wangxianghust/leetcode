/*判断一个数是不是Ugly Num
 * Ugly Num  是指只有2，3，5这些素数因子的
 * Solution：直接连续除法判断
 */

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num%5 == 0) num /= 5;
        while(num%3 == 0) num /= 3;
        while(num%2 == 0) num /= 2;
        return num == 1;
    }
};

int main(){
    //AC
}
