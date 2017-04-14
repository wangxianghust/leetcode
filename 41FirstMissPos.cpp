/*问题：首先要理解题意，在1~INT_MAX中，没有出现过的正整数。如1 3 4 --> 2   1 2 3 -->4  10 12-->1
 * Solution: 问题的解决类似于桶排序，我们只考虑大小在1~size内的数字，其他不可能
 * 然后，我们遍历数组，将每个ele放在它应该在的地方，eg, 3在nums[2], 1在nums[0],
 * 第二次遍历数组，一旦发现 nums[i] != i+1, 则发现这个整数 i+1;
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        //可以这样理解：每个元素所在位置是一个坑，现在要将合法的元素填到坑里
        //while循环内是判断元素是否合法，由于每次执行while循环，要么swap后坑内元素不合法，要么第一次检测不合法直接跳过
        //总之坑是有限的，最终会遍历完，同时由于while的存在，每一个合法的元素都进行了找坑。
        for(int i=0; i<size; ++i){
            while(nums[i]>0 && nums[i]<size && nums[nums[i]-1] != nums[i]) //ele is not at right place.
                swap(nums[nums[i]-1], nums[i]);
        }

        for(int i=0; i<size; ++i){
            if(nums[i] != i+1) return i+1;
        }
        
        return size+1;
    }
};

int main(){
    freopen("41test.txt", "r", stdin);
    int total; cin >> total;
    for(int i=0; i<total; ++i){
        Solution Sol;
        int size; cin >> size;
        vector<int> nums;
        for(int i=0; i<size; ++i){
            int c; cin >> c;
            nums.push_back(c);
        }
        int ret = Sol.firstMissingPositive(nums);
        cout << ret << endl;
    }
}

