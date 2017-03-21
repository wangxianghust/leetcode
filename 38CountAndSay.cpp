#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ret = to_string(1);//the seed is 1
        return process(n, ret);     
    }
private:
    string process(int n, string ret){
        if(n == 1) return ret;
        string inter_ret = "";
        int size = ret.size();
        for(int i=0; i<size; ++i){
            int num = 1;
            while(i<size-1 && ret[i] == ret[i+1]) {
                ++i;
                ++num;
            }
            inter_ret += to_string(num) + ret[i];
        }
        //cout << "test- " << inter_ret << endl;
        return process(--n, inter_ret);
    }
};

int main(){
    freopen("38test.txt", "r", stdin);
    int total;
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int n;
        cin >> n;
        cout << Sol.countAndSay(n) << endl; 
    }
}
