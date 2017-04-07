#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> &a, pair<int, int> &b){
    return a.first < b.first;
}

class Solution{
public:
    int DestroyCars(vector<pair<int,int> > &input){
        //still have problems
        int size = input.size();
        return 
    }
private:
    int DestroyOne(vector<pair<int,int>> &input){
        int size = input.size();
        set<int> index;
        for(int i=0; i<size; ++i){
            int time = input[i].first;
            // I still have some problems.
        }
    }
};

int main(){
    int total;
    cin >> total;
    int start, len;
    vector<pair<int,int> > input;
    while(total--){ 
        cin >> start >> len;
        input.push_back(make_pair(start, start+len));
    }
    sort(input.begin(), input.end(), cmp);
    Solution Sol;
    cout << Sol.DestroyCars(input) << endl;
}
