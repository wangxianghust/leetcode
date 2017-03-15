/*Problem 3个和为0； 
 * 思路1：遍历数组中的每个，转化为2sum 问题,如threeSum_
 *      But, 在去重环节的处理上存在问题，Time Limit Exceeded.
 * 思路2：排序，排序后得到一个结果后，直接跳过相同的结果呀，使用头指针和尾指针方案。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum_(vector<int>& nums) {
        unordered_map<int, int> book;  //<needed num, index>
        vector<vector<int> > ret;
        vector<int> three;
        for(int i=0; i<nums.size(); ++i){
            int target = -nums[i];
            for(int j=i+1; j<nums.size(); ++j){
                //if(j == i) continue;
                if(book.find(nums[j]) == book.end()){
                    book[target - nums[j]] = j;
                } else {
                    three.push_back(-target);
                    three.push_back(nums[j]);
                    int index = book[nums[j]];
                    three.push_back(nums[index]);
                    ret.push_back(three);
                    three.clear(); 
                }
            }
            book.clear();
        }
        for(auto &i : ret) sort(i.begin(), i.end());
        set<vector<int> > set_;
        for(auto i : ret) set_.insert(i);
        ret.clear();
        for(auto i : set_) ret.push_back(i);
        return ret;
    }

public:
    vector<vector<int> > threeSum(vector<int>& nums){
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i=0; i<size; ++i){
            int target = -nums[i];
            int front = i+1;
            int back = size-1;
            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum < target){
                    ++front;
                } else if(sum > target){
                    --back;
                } else {
                    vector<int> three(3,0);
                    three[0] = nums[i];
                    three[1] = nums[front];
                    three[2] = nums[back];
                    ret.push_back(three);
                    //NOTICE: there must front < back, not front+1<back ,or nums[front]
                    //--->because the pointer must go on moving.
                    while(front<back && nums[front] == three[1]) ++front;
                    while(back>front && nums[back] == three[2]) --back;             
                }
            }
            while(i+1 < size && nums[i+1] == -target) ++i;
        }
        return ret;
    }
};

void print(vector<vector<int> > ret){
    for(auto i: ret){
        for(auto j : i){
            cout << j << " ";
        }
        cout << "<->";
    }
    cout << "next layer " << endl;
}

int main(){
    Solution Sol;
    freopen("15test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        int size;
        cin >> size;
        vector<int> nums;
        for(int j=0; j<size; ++j){
            int s;
            cin >> s;
            nums.push_back(s);
        }
        print(Sol.threeSum(nums));
    }
}
