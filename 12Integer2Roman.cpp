#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const int size = 13;
        string ret("");
        int Int[size] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string Roman[size] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i=0; i<size; ++i){
            while(num >= Int[i]){
                ret += Roman[i];
                num -= Int[i];
            }
        }
        return ret;
    }
};

int main(){
    Solution Sol;
    freopen("12test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        int num;
        cin >> num;
        cout << Sol.intToRoman(num) << endl;
    }
}
