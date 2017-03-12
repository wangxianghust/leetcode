#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse_(int x) { //case -2147483648 can not pass, why ?
        int y = abs(x);
        vector<int> digit;
        while(y){
            digit.push_back(y%10);
            y /= 10;
        }
        long int ret = 0;
        int size = digit.size();
        for(int i=size-1; i >= 0; --i){
            ret += digit[i] * pow(10, size-1-i);
            //ret = ret*10 + digit[i];
        }
        
        if(x <= 0){
            return -ret < INT_MIN ? 0 :(int)-ret;
        } else {
            return ret > INT_MAX ? 0 : (int)ret;
        }
    }

public:
    int reverse(int x){
        int ret = 0;
        int temp = 0;
        long int long_ret  = 0;
        while(x){
            temp = x % 10;
            x /= 10;
            ret = ret*10 + temp;
            long_ret = long_ret*10 + temp;
        }
        if(long_ret != ret) return 0;
        return ret;
    }
};

int main(){
    int x;
    int total;
    freopen("7test.txt", "r", stdin);
    cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        cin >> x;
        cout << Sol.reverse_(x) << endl;
        cout << "another : " << Sol.reverse(x) << endl;
    }   
    // test for overfolw
    //int y = 9147483646;
    //cout << INT_MAX << endl; 
    //cout << y << endl;
    cout << INT_MAX << " " << INT_MIN << endl;
}
