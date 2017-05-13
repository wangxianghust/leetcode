/* 给小孩子分candy(每个孩子有一个分数)，要求1.每个孩子至少一个糖果 2.高分数的孩子比邻居数量多
 * Solution：开一个数组，初始化为1，从左向右找递增序列，依次加一，从右向左(why? 因为最小的值要赋值为1)寻找
 * 递增序列，依次加一(和之前不同的是，需要选择和之前中的max)
 * 此解法有一个小问题：相同rating的孩子得到的数量可能不一样，不过OJ可以过，所以暂时我认为rating是离散的吧。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size(); 
        if(size == 0) return 0;
        int ret(0);
        vector<int> nums(size, 1);

        for(int i=1; i<size; ++i){
            if(ratings[i] > ratings[i-1]){
                nums[i] = nums[i-1] + 1;
            }
        }

        for(int i=size-2; i>=0; --i){
            if(ratings[i] > ratings[i+1] ){
                nums[i] = max(nums[i], nums[i+1]+1);
            }
        }

        for(int i : nums) {
            ret += i;
            cout << i << endl;
        }
        return ret;
    }
};

int main(){
    Solution Sol;
    vector<int> nums{1,2,2,3,1};
    Sol.candy(nums);
}
