/*问题：给定宽度为1，高度不同的非负高度，求最大的矩形面积
 * 方法：简单的用n^2可以
 * 优化？
 */

#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int size = heights.size();
        int largest = 0;
        stack<int> sta; //save the index
        int i = 0;
        int tp = 0;
        int width = 0;
        int tmp = 0;
        while(i < size){
            if(sta.empty() || heights[sta.top()] <= heights[i]){
                //add the larger num to stack
                sta.push(i++);
            } else {
                tp = sta.top();
                sta.pop();
                width = sta.empty() ? i : (i-sta.top()-1);
                tmp = heights[tp] * width;
                if(largest < tmp) largest = tmp;
            }
        }
        while(!sta.empty()){
            tp = sta.top();
            sta.pop();
            width = sta.empty() ? i : (i-sta.top()-1);
            tmp = heights[tp] * width;
            if(largest < tmp) largest = tmp;
        }
        return largest;
    }
    //WA 95/96, it is the right answer, but TLE...
    int largestRectangleArea_(vector<int>& heights) {
        int size = heights.size();
        int largest = 0;
        for(int i=0; i<size; ++i){
            int from_i_largest = 0;
            int small_height = heights[i]; //denote the smallest height from i on.
            for(int j=i; j<size; ++j){
                if(heights[i] == 0) break;
                if(small_height > heights[j]) small_height = heights[j];
                int tmp = small_height*(j-i+1);
                if(from_i_largest < tmp) from_i_largest = tmp;
            }
            if(largest < from_i_largest) largest = from_i_largest;
        }
        return largest;
    }
};

int main(){
    //AC
}
