/* 股票盈利问题，最多可以进行两次买卖，求最大profit
 * Solution: 使用的是四个状态，然后转换：one buy, one buy and one sell, 2buy and 1sell, 2buy and 2sell..
 * 也就是每个点都可能做出上述四种states中某种的决策，然后后一个只和前面一个有关。
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int state[2][4] = {INT_MIN, 0, INT_MIN, 0}; // 1buy, 1buy & 1sell, 2buy & 1sell, 2buy &2sell;
        int cur(0), next(1);
        for(auto i : prices){
            state[next][0] = max(state[cur][0], -i);
            state[next][1] = max(state[cur][1], state[cur][0]+i);
            state[next][2] = max(state[cur][2], state[cur][1]-i);
            state[next][3] = max(state[cur][3], state[cur][2]+i);
            swap(cur, next);
        }
        return max(state[cur][1], state[cur][3]);
    }
};
