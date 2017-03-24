/*问题：顺时针90度旋转一个二维矩阵
 * 解法：先将矩阵按照行进行翻转，第一行到最后一行，etc... 然后将举证进行对称。
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int i = 0; 
        int j = size - 1;
        while(i < j){
            swap(matrix[i++], matrix[j--]);
        }

        for(int i=0; i<size; ++i){
            for(int j=i+1; j<size; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void print(vector<vector<int> > ret){
        for(auto item : ret){
            for(int i : item) cout << i << " ";
            cout << endl;
        }
        cout << "---" << endl;
    }
};

int main(){
    freopen("48test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<vector<int> > matrix(size, vector<int>(size));
        for(int i=0; i<size; ++i){
            for(int j=0; j<size; ++j){
                int c; cin >> c;
                matrix[i][j] = c;
            }
        }
        Sol.print(matrix);
        Sol.rotate(matrix);
        Sol.print(matrix);
    }
}
