/*问题：给定一个二维的矩阵，包含0和1，求由1组成的长方形的最大面积
 * 解决：利用上一题求解不同height的rectangle的最大值结果，现在row by row求解
 * 所能得到的面积值，然后选择最大(迭代选择好每层row的height就好)
 *
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template<typename T>
void print(vector<vector<T> > matrix){
    for(auto i : matrix){
        for(T j : i)cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int ret = 0;
        vector<vector<int> > height(row, vector<int>(col, 0));
        for(int j=0; j<col; ++j) height[0][j] = matrix[0][j] - '0';
        for(int i=1; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(matrix[i][j] == '0') height[i][j] = 0; //if the current row is 0, then the height will be 0 wheneve the 0  above.
                else height[i][j] = height[i-1][j] + (matrix[i][j] - '0');
            }
        }
        print(matrix);
        print(height);
        for(int i=0; i<row; ++i){
            int tmp = maximalRectangle(height[i]);
            cout << "row " << i << " max_rect is " << tmp << endl;
            if(ret < tmp) ret = tmp;
        }
        return ret;
    }

private:
    int maximalRectangle(vector<int> & height){
        int size = height.size();
        int i;
        int max_rect = 0;
        int tmp_max = 0;
        stack<int> sta;  //save the Index Not height.cause from the index can lookup the height.
        int tp = 0; //the index of top ele of stack.
        for(i=0; i<size;){ //means we choose the i-th height, then get the maximalRectangle.
            if(sta.empty() || height[i] >= height[sta.top()]){
                sta.push(i++);
                //cout << "push " << i << endl;
            } else {
                tp = sta.top();
                sta.pop();
                int width = sta.empty() ? i : i-sta.top()-1; //there must be i-sta.top()-1, NOT i-tp.
                tmp_max = width * height[tp];
                //cout << "height " << i << " area is " << tmp_max << endl;
            }
            if(max_rect < tmp_max) max_rect = tmp_max;
        }
        while(!sta.empty()){
            tp = sta.top();
            sta.pop();
            int width = sta.empty() ? i : i-sta.top()-1; //top is the previous valid index to calculate with now index.
            tmp_max = width * height[tp];
            //cout << "height " << i << " area is " << tmp_max << endl;
            if(max_rect < tmp_max) max_rect = tmp_max;
        }
        return max_rect;
    }
};

int main(){
    freopen("85test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        int row, col;
        cin >> row >> col;
        vector<vector<char>> matrix(row, vector<char>(col, '0'));
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                char c; cin >> c;
                matrix[i][j] = c;
            }
        }
        cout << Sol.maximalRectangle(matrix) << endl;
    }
}
