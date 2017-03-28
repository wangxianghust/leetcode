#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int right = n-1;
        int bottom = n-1;
        int left = 0;
        int top = 0;
        vector<vector<int> > ret(n, vector<int>(n));
        int i = 1;
        while(i <= n*n){
            for(int column=left; column<=right; ++column) ret[top][column] = i++;
            if(++top > bottom) break;

            for(int row=top; row<=bottom; ++row) ret[row][right] = i++;
            if(--right < left) break;

            for(int column=right; column>=left; --column) ret[bottom][column] = i++;
            if(--bottom < top) break;

            for(int row=bottom; row>=top; --row) ret[row][left] = i++;
            if(++left > right) break;
        }
        return ret;
    }

public:
    void print(vector<vector<int>> ret){
        for(auto item : ret){
            for(int i : item) cout << i << " ";
            cout << endl;
        }
    }
};

int main(){
    //AC
    Solution Sol;
    auto ret = Sol.generateMatrix(5);
    Sol.print(ret);
}
