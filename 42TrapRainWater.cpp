/*题目：给定一组台阶的海拔图，台阶的宽度是1，问能装多少水？
 * 解答：1. 发现降序然后升序的队列，计算该序列可以盛水的量，计算方法：寻找两边高度最小的台阶，
 * 向另一个方向遍历(相减就可以) 2.注意右边台阶可以复用，同时要去重。
 * 上述方法138/315,没有考虑所有的问题。
 *
 * 修改：Accumulate:计算每一个台阶可以放的water，最后累加求和。
 * 要从首尾向中间遍历（因为要选一个小的作为level，eg, left < right; 说明right的wall很高，不会违反条件）
 * 遍历的时候要不断更新左右边的max_high，max_high-height[i]是台阶i可以放的水，
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height){
        int right = height.size()-1;
        int left = 0;
        int max_left = 0;
        int max_right = 0;
        int ret = 0;
        while(left <= right){ //condition
            if(height[left] <= height[right]){ //now we can consider left side only.
                if(height[left] >= max_left){
                    max_left = height[left];
                } else {
                    ret += max_left - height[left];
                }
                ++left;
            } else {
                if(height[right] >= max_right){
                    max_right = height[right];
                } else {
                    ret += max_right - height[right];
                }
                --right;
            }
        }
        return ret;
    }
    
    int trap_(vector<int>& height) {
        int size = height.size();
        int start = 0;
        int ret = 0;
        while(start+1 < size && height[start] <= height[start+1]) ++start; //ascending order,skip,to find start.
        for(int i=start; i+1<size;){ //the last height can not be a start.
            while(i+1 < size && height[i] == height[i+1]) ++i; //skip duplicate.
            int m = i;
            int n = 0;
            while(i+1 < size && height[i] >= height[i+1]) ++i; //the first step, decrease.
            if(i+1 < size && height[i] < height[i+1]){ //want to find asc and size is legal.
                //while(i+1 < size && height[i] == height[i+1]) ++i;
                while(i+1 < size && height[i] < height[i+1]) ++i; //go on decrease.
                n = i;
                int h = min(height[m], height[n]);
                for(int j=m; j<=n; ++j){
                    if(h-height[j] > 0) ret += (h-height[j]);
                }
            }
            //cout << m << " " << n << endl;
        }
        return ret;
    }
};

int main(){
    freopen("42test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<int> height;
        for(int j=0; j<size; ++j){
            int c; cin >> c;
            height.push_back(c);
        }
        int ret = Sol.trap(height);
        cout << ret << endl;
    }
}
