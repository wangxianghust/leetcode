/*给定一些二维Points, 求会在一个line上的点最多是多少
 * Solution：首先定下问题的下限，由于必须知道每两个节点之间的斜率才可以求最值，所以至少是O(n^2)
 * 先求含有节点1的所有直线对，用hash_map 统计斜率的数量，求最大值。 同理对于节点2，3... 最后取以上所有max的max即可
 * 注意点：1. 检查是否含有相同的点； 2. 同一vertical line要单独统计，因为斜率为无穷大(x值相等)； 
 * 3. double最为map的key，没有 gcd = GCD(a,b), pair<a/gcd, b/gcd> 来得好。
 */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        
    }
};
