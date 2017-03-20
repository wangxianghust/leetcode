/*这题从结尾开始进行遍历，直到找到升序对，然后调换位置
 * 4 7, 然后找到后面第一个比4大的数字，此处为5，swap,然后reverse后面这个序列
 * 如 4 7 5 3 2 变为  7 2 3 4 5
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size -1;
        while(i>0 && nums[i-1] >= nums[i]) --i;
        if(i == 0) {
            reverse_(nums, 0, size-1);
            return;
        }
        int smaller_than_next = nums[i-1];
        int j = i+1;
        while(j<size && smaller_than_next < nums[j]) ++j;
        //int first = nums[j-1];
        swap(nums[i-1], nums[j-1]);
        reverse_(nums, i, size-1);
    }
private:
    void reverse_(vector<int> &nums, int start, int end){
        while(end > start){
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    }
};

void print(vector<int> ret){
    for(auto i : ret) cout << i << " ";
    cout << endl;
}

int main(){
    freopen("31test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size;
        vector<int> nums;
        cin >> size;
        for(int j=0; j<size; ++j){
            int c;
            cin >> c;
            nums.push_back(c);
        }
        print(nums);
        Sol.nextPermutation(nums);
        print(nums);
        cout << "---" << endl;
    }
}




