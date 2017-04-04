/*Problem: 给定任一顺序的0，1，2，不用排序的方法，最后得到0，1，2的顺序排列
 * Solution: Two pointers
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //one pointer save the location of 0, one is 2, and another one to iterate the array
        int start = 0;
        int end = nums.size()-1;
        for(int i=0; i<=end;){
            if(nums[i] == 0){
                swap(nums[i++], nums[start++]);
            } else if(nums[i] == 2){
                swap(nums[i], nums[end--]);
            } else {
                ++i;
            }
        }
    }
};

int main(){
    freopen("75test.txt", "r", stdin);
    int total; cin >> total;
    while(total--){
        int size; cin >> size;
        vector<int> nums(size,0);
        for(int i=0; i<size; ++i) {
            int c; cin >> c;
            nums[i] = c;
        }
        Solution Sol;
        Sol.sortColors(nums);
        for(auto i:nums) cout << i << " ";
        cout << endl;
    }
}
