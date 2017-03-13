#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        int y = x;
        while(x){
            int num = x % 10;
            sum = sum*10 + num;
            x /= 10;
        }
        if(sum == y) return true;
        else return false;
    }
};

int main(){
    freopen("9test.txt", "r", stdin);
    Solution Sol;
    int total;
    cin >> total;
    int x;
    for(int i=0; i<total; ++i){
        cin >> x;
        cout << Sol.isPalindrome(x) << endl;
    }
}
   
