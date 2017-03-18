#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    //ERROR : Time Limit Exceeded
    string getPermutation(int n, int k) {
       //permutation("", n, k);
       count =  k;
       permutation("", n);
       return ret;
    }

private:
    void permutation(string str, int n){
        if(str.size() == n){
            --count;
            //cout << "test " << count << "---" << str << endl;
            if(0 == count)
                ret = str;
            return;
        }

        for(int i=1; i<=n; ++i){
            if(0 == count) return;
            bool isSafe = str.find(to_string(i)) == string::npos;//Not find in previous, can add new.
            if(isSafe){
                permutation(str + to_string(i), n);
            }
        }
    }

private:
    string ret;
    int count;
};

int main(){
    freopen("60test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int n,k;
        cin >> n >> k;
        cout << "answer " << Sol.getPermutation(n, k) << endl;
    }
}
