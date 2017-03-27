/*问题：首先要理解题意，在1~INT_MAX中，没有出现过的正整数。如1 3 4 --> 2   1 2 3 -->4  10 12-->1
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
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

