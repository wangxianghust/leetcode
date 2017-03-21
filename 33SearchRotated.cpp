/*题目意思：一个sorted数组，rotate一次，然后用二分查找target
 * solutions是对二分查找进行修改，设rotate的节点是一个drop，不断迭代找到
 * 一个区间，drop不在其中，target在其中即可
 * 3 4 5 1 2   trick：查找1，可以将左边的值设置为INT_MIN，
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size-1;
        while(low <= high){
            int mid = (high - low)/2 + low; // (high+low)/2 may overstack.
            if(nums[mid] == target) return mid;
            long long num;
            if( (nums[mid] < nums[0]) == (target < nums[0]) ){//nums[0] is a drop flag.
                num = nums[mid];  //nums[mid] and nums[0] is the same side of drop.
            } else {
                if(target < nums[0] ){
                    num = LLONG_MIN;//target is on the right of mid
                } else {
                    num = LLONG_MAX;
                }
            }
            if(target > num){
                low = mid+1;
            } else {
                high = mid-1;
            }   
        }
        return -1;
    }
};

int main(){
    freopen("33test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    //cout << INT_MIN << " " << INT_MAX << endl;
    //cout << LLONG_MIN << " " << LLONG_MAX << endl;
    for(int i=0; i<total; ++i){
        int target;
        int size;
        vector<int> nums;
        cin >> target;
        cin >> size;
        for(int j=0; j<size; ++j){
            int c;
            cin >> c;
            nums.push_back(c);
        }
        auto ret = Sol.search(nums, target);
        cout << ret << endl;
    }
}


