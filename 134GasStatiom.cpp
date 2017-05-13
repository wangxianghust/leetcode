/* 给定一个环形公路，上面有gas station，供油量是gas[i],每两个gas之间的耗油量是cost[i]，
 * 汽车在每个station可以无限制的加油，问是否可以找到一个start station 让汽车可以环形整个公路
 * Solution：简单的方法有，暴力，选择一个起点，走一圈index = (start + step) % size,复杂度N^2
 * 换一个思路，如果 start-->k 是无法通的，那么start到k中的任何一个点都是不可以的，所以可以不从i+1在开始，
 * 而是从k+1开始，这样是O(2n)，还可以再简化！可以证明 total >= 0 则必定有解， total = sum(diff[i]), i= [0,n)
 * 因此O(n)的算法即可。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size()) return -1; 
        int start(0), total(0), sum(0), size(gas.size());
        for(int i=0; i<size; ++i){
            int diff = gas[i] - cost[i];
            total += diff;
            if(sum < 0){
                //from next station to start
                start = i; 
                sum = diff;  //here next sum is diff, NOT 0.
            } else {
                sum += diff;
            }
        }
        return (total >= 0) ? start : -1;
    }
};
