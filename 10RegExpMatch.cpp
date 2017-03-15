#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //if(s.empty() || p.empty()) return false;  //the judge think empty is a space, so ignore this.
        int s_len = s.length() ;
        int p_len = p.length() ;
        vector<vector<bool> > book(s_len+1, vector<bool>(p_len+1, false)); //save the answer of Is s.len and p.len return true
        //initialization of DP, book[j][0] must be false, but book[0][j] we should handle it.
        book[0][0] = true;
        for(int j=0; j<p_len; ++j){
            if(p[j] == '*' && book[0][j-1]){
                book[0][j+1] = true;  //This is j+1 not j, p[j] have the length j.
            }
        }
        for(int i=0; i<s_len; ++i){ //It is discussing the value of p[j]
            for(int j =0; j<p_len; ++j){
                if(s[i] == p[j] || p[j] == '.'){
                    book[i+1][j+1] = book[i][j];
                }
                if(p[j] == '*'){
                    if(p[j-1] != s[i] && p[j-1] != '.'){//means p[j-1] cannot match the s[i]
                        book[i+1][j+1] = book[i+1][j-1]; //* means zero here.
                    } else {
                        //*means zero, one, multi.
                        book[i+1][j+1] = (book[i+1][j-1] || book[i+1][j] || book[i][j+1]);
                    }
                }
                //else is s[i] != p[j], which must be false.
            }
        }
        return book[s_len][p_len];
    }
};

int main(){
    freopen("10test.txt", "r", stdin);
    Solution Sol;
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        string s;
        string p;
        cin >> s;
        cin >> p;
        cout << s << " " << p << " " << Sol.isMatch(s,p) << endl;
    }
    string s = "";
    string p = ".*";
    p = "c*";
    cout << s << "--" << p << "--" << Sol.isMatch(s,p) << endl;
}

