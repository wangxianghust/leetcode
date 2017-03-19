#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k){
        string ret(n, '0');
        vector<int> factorial(10,1);
        for(int i=1; i<10; ++i){ //factorial[i] = i!
            factorial[i] = factorial[i-1] * i;
        }
        vector<char> nums; //123..9
        for(int i=1; i<10; ++i){
            nums.push_back('0'+i);
        }
        int i = 0;
        while(n){
            int index = (k-1)/factorial[n-1];//there must be k-1, cause we want to know the numbers before k.
            ret[i++] = nums[index];
            nums.erase(nums.begin() + index);
            k = k - index*factorial[n-1];
            --n;
        }
        return ret;
    }
public:
    //ERROR : Time Limit Exceeded
    string getPermutation_(int n, int k) {
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
        cout << "backtracking " << Sol.getPermutation_(n, k) << endl;
    }
}
