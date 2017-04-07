#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution{
public:
    int FindThief(string &str){
        int size = str.size();
        set<int> thief;
        for(int i=0; i<size; ++i){
            if(str[i] >= '1' && str[i] <= '9'){
                int len = str[i] - '0';
                int start = i - len;
                int end = i + len;
                start = (start >= 0) ? start : 0;
                end = (end < size) ? end : size-1;
                for(int j=start; j<=end; ++j){
                    if(str[j] == 'X')thief.insert(j);
                }
            }
        }
        return thief.size();
    }
};

int main(){
    int size; 
    cin >> size;
    string str;
    cin >> str;
    Solution Sol;
    cout << Sol.FindThief(str) << endl;
}
