/* 给定一个数组，问是否存在两个数的值差最多为t,下标距离最大为k
 * Solution:借助桶排序的思想，设置桶的大小为 t+1,同时维护一个map的大小为k，
 * 判定条件是在相同的桶内，或者旁边的桶内同时差值不超过k。
 */ 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t<0 || k<0) return false;
        long w = (long)t + 1;
        unordered_map<long, long> bucket_val;
        int size = nums.size();
        for(int i=0; i<size; ++i){
            long id = getID(nums[i], w);
            if(bucket_val.find(id) != bucket_val.end()) return true;
            if(bucket_val.find(id+1) != bucket_val.end() &&  abs(bucket_val[id+1]-nums[i]) <= t) return true;
            if(bucket_val.find(id-1) != bucket_val.end() &&  abs(bucket_val[id-1]-nums[i]) <= t) return true;
            bucket_val[id] = nums[i];
            if(i>=k) bucket_val.erase( bucket_val.find(getID(nums[i-k], w)) );//当map的数量超过k的时候，不断的从前面进行删除。
        }
        return false;
    }
private:
    long getID(int n, int w){
        //n是数字，w是窗口大小，判定给定数字属于哪个桶，注意对负数的处理
        return (n<0) ? (n+1)/w -1 : n/w;
    }
};

int main(){
    
}
