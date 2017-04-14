/*Problem: 字符串匹配，？match any char, * match sequence include space
 * Solution: DP
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p){
        int m(s.size()), n(p.size()), i_star(-1), j_star(-1);
        int i(0), j(0);
        for( ; i<m ; ++i, ++j){ //If j is p.size(), the p[j] = '\0', can also run
            if(p[j] == '*'){
                i_star = i;
                j_star = j;
                --i; //take * as a empty string
            } else if(p[j] != s[i] && p[j] != '?'){
                if(i_star >= 0){
                    i = i_star; // take *as empty is fail, take * as one char;
                    j = j_star;
                    ++i_star; // next fail, thak * as two chars.
                } else {
                    return false; // No match and no *, must fail.
                }
            }
        }
        while(p[j] == '*') ++j;
        return j == n;
    }

    bool isMatch_DP(string s, string p) {
        //book[i][j] means IS s[0..i] matches p[0..j];
        int m = s.size();
        int n = p.size();
        vector<vector<bool> > book(m+1, vector<bool>(n+1, true));
        //Initialization, if s is null, p must be all '*'
        for(int j=0; j<n; ++j){
            book[0][j+1] = (p[j] == '*' && book[0][j]) ? true : false;
        }
        for(int i=1; i<=m; ++i) book[i][0] = false;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){ //for every small s, use p to match.
                if(p[j] == s[i] || p[j] == '?'){
                    book[i+1][j+1] = book[i][j];
                } else if(p[j] == '*'){
                    //first means s[0...i-2] match p[0...j-1], * match s[i-1], second means s[0...i-1] match p[0..j-2], * is empty.
                    book[i+1][j+1] = book[i][j+1] || book[i+1][j]; 
                } else {
                    book[i+1][j+1] = false;
                }
            }
        }
        return book[m][n];
    }
};

int main(){
    freopen("44test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        string s, p;
        cin >> s >> p;
        cout << "Greedy : " << Sol.isMatch(s, p) << endl;
        cout << "DP : " << Sol.isMatch_DP(s, p) << endl;
    }
}
