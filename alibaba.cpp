#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Alibaba {
public:
    
private:

public:
    void print(vector<vector<string> > ret){
        for(auto i : ret){
            for(string j : i)cout << j << " ";
            cout << endl;
        }
        cout << "---" << endl;
    }
};

int main(){
    freopen("ali.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        
    }
    
}

