/* 计算论文引用的H-index，也就是 paper的数量， 并且 这些paper的reference大于paper的数量，如
 * 有3篇paper的引用是4，则 h=3,  有4篇paper的引用是4，则 h=4
 * Solution: 桶排序，桶的数量是paper的数量，大于 #paper的放在最后一个bucket,最后从后向前遍历bucket，
 * 一旦发现paper的累积数量大于下标（即index）即为答案。
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if(size == 0) return 0;
        vector<int> bucket(size+1, 0);
        for(int ci : citations){
            if(ci >= size){
                bucket[size] ++;
            } else {
                bucket[ci] ++;
            }
        }

        for(int i=size; i>0; i--){
            if(bucket[i] >= i) return i;
            else {
                bucket[i-1] += bucket[i];
            }
        }
    }
};

int main(){
    
}
