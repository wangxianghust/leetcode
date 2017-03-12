#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if(size & 1){
            return findKth(nums1, nums2, 0, 0, size/2+1);
        } else {
            return (findKth(nums1, nums2, 0, 0, size/2) + findKth(nums1, nums2, 0, 0, size/2+1))/2;
        }       
    }
private:
    double findKth(vector<int> &nums1, vector<int> &nums2, int start1, int start2, int kth){//kth means that there are kth-1 eles before it.
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        //handle the base cases of recursive find.
        if(start1 >= size_1) return nums2[start2 + kth - 1];
        if(start2 >= size_2) return nums1[start1 + kth - 1];
        if(1 == kth) return min(nums1[start1], nums2[start2]); 
        
        int key1 = (start1 + kth/2 -1 >= size_1) ? INT_MAX : nums1[start1 + kth/2 -1]; 
        int key2 = (start2 + kth/2 -1 >= size_2) ? INT_MAX : nums2[start2 + kth/2 -1]; 
        if(key1 < key2){
            return findKth(nums1, nums2, start1 + kth/2, start2, kth - kth/2); //notice we decrease kth/2 nodes every process, we cannot use kth/2 here.
        } else {
            return findKth(nums1, nums2, start1, start2 + kth/2, kth - kth/2);
        }
    }
};

int trans(string &a){
    int res = 0;
    for(int i=0;i<a.size();i++)
        res = res * 10 + a[i] - '0';
    return res;
}

// customed split function for string process
vector<string> split(const string &s, const string &delim) {
	vector<string> res;
	string::size_type front = 0;
	string::size_type last = s.find_first_of(delim, front);
	while (last != string::npos) {
		if (last > front) {
			string tmp = s.substr(front, last - front);
			res.push_back(tmp);
		}
		front = last + 1;
		last = s.find_first_of(delim, front);
	}
	if (last > front) {
		res.push_back(s.substr(front, last - front));
	}
	return res;
}

int main(){
    //vector<int> nums1{1,2,3};
    //vector<int> nums2{4,5,6,7};
    freopen("4test.txt", "r", stdin);
    string s;
    getline(cin, s);
    int cases = trans(s);
    getline(cin , s);
    auto ret = split(s, " ");
    //vector<int> nums1(ret.size(), 0);
    //for(auto &i : ) ret[] = trans(i);
    //cout << cases << endl;
    //Solution Sol;
    //cout << Sol.findMedianSortedArrays(nums1, nums2) << endl;
}
