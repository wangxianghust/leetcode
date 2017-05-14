/*给定一个无须的数组，要求将数组排序后，求相邻两数字差的max,时间要是O(n), eg 1 3 10 5 6 --> 1 3 5 6 10 max=10-6=4
 * Solution:O(n),就是桶排序了，多少个bucket？bucket多大合适？
 * 我们先看看要求结果的下限，就是gap = (max_ele-min_ele)/(size-1); 所以每个bucket的大小为gap，共有size-1个bucket
 * 这样再求结果的时候，我们不用考虑bucket内部的值比较，只用关心bucket之间的，同时只用两个数组分别存bucket中的min和max即可。
 */

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
    }
};
