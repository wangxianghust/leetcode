/*Merge two sorted array into the first one
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(j >= 0) {//put nums2 to nums1, from the nums1'end to nums1'first, once nums is over, which is sorted.
            nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
    //this need m+n more space.see the above.
    void merge_(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ret(m+n, 0);
        int k=0;
        int i,j;
        for(i=0, j=0; i<m && j<n;){
            if(nums1[i] <= nums2[j]){
                ret[k++] = nums1[i++];
            } else {
                ret[k++] = nums2[j++];
            }
        }
        if(i == m){
            while(j<n)ret[k++] = nums2[j++];
        } else {
            while(i<m)ret[k++] = nums1[i++];
        }
        nums1 = ret;
    }
};

int main(){
    //AC
}
