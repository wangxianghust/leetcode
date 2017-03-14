#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //this method is error, cause the complexity is n*n.Time Limit Exceeded.
    int maxArea_(vector<int>& height) {
        int size = height.size();
        int max_area = 0;
        //int x, y;
        for(int i=0; i<size-1; ++i){
            for(int j=i+1; j<size; ++j){
                int tmp = (j-i)*min(height[i], height[j]);
                if(tmp > max_area){
                    max_area = tmp;
                    //x = i;
                    //y = j;
                } 
            }
        }
        //cout << x << "--" << y << endl;
        return max_area;
    }
    
    //use two pointer, from the start and end to visit.
    int maxArea(vector<int>& height){
        int i = 0;
        int j = height.size()-1;
        int water = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            water = max(water, (j-i)*h);
            while(i < j && height[i] <= h) ++i;//Do not forget the =, or the index will not go on.
            while(i < j && height[j] <= h) --j;
        }
        return water;
    }
};

int main(){
    Solution Sol;
    freopen("11test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        int size;
        cin >> size;
        vector<int> height;
        for(int j=0; j<size; ++j){
            int ele;
            cin >> ele;
            height.push_back(ele);
        }
        int ret = Sol.maxArea_(height);
        cout << ret << endl;
        cout << Sol.maxArea(height) << endl;
    }
}
