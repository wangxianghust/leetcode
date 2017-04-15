/*Problem: Input a string, get all valid IP address, 1~255.0~255.0~255.0~255
 * Solution: 回溯
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int size(s.size());
        if(size < 4 || size > 12) return ret;
        int index = 0;
        restore(s, "", 0, index, size, ret);
        return ret;
    }

private:
    void restore(string s, string ip, int ip_num, int index, int size, vector<string> &ret){
        if(ip_num > 4) return;
        if(ip_num == 4 && index == size) {
            ret.push_back(ip);
            return;
        }        
        for(int i=1; i<4; ++i){
            if(index+i > size) break;
            string now = s.substr(index, i);// c++ substr is not same as java.
            if(isValid(now)){
                string ip_new = ip + now + ((ip_num==3) ? "" : ".");
                restore(s, ip_new, ip_num+1, index+i, size, ret);
            }
        }
    }
private:
    bool isValid(string ip_one){
        int size = ip_one.size();
        if(size==0 || (ip_one[0] == '0' && size > 1) || size>4 || stoi(ip_one) > 255)return false;
        else return true;
    }
};

void print(vector<string> s){
    for(auto i : s) cout << i << endl;
    cout << endl;
}

int main(){
    //AC
    freopen("93test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        string s; cin >> s;
        auto ret = Sol.restoreIpAddresses(s);
        print(ret);
    }
}
