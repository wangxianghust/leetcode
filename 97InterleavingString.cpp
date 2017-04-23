/*Problem: 给定两个string, s1, s2, 从其中一个开始交叉行走，是否能够得到s3
 * Soloution: DP, book[i][j] means the i-length s1 + j-length s2 to get s3[0..i+j-1] ?
 */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size()) return false;
        vector<vector<bool> > book(m+1, vector<bool>(n+1, false));
        book[0][0] = true;
        for(int i=1; i<=m; ++i) book[i][0] = book[i-1][0] && (s1[i-1] == s3[i-1]);
        for(int j=1; j<=n; ++j) book[0][j] = book[0][j-1] && (s2[j-1] == s3[j-1]);
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                book[i][j] = (book[i][j-1] && s2[j-1] == s3[i+j-1]) || (book[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }
        return book[m][n];
    }
};

int main(){
    //AC
}
