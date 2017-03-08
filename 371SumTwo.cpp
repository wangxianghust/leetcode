#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        vector<int> aa(Int2Bits(a));
        vector<int> bb(Int2Bits(b));
        vector<int> ret;
        if(aa.size() < bb.size()) swap(aa,bb);
        int c = 0;
        for(int i=0; i<bb.size(); ++i){
            if(aa[i] & bb[i] & c){
                ret.push_back(1);
                c = 1;
            } else if((aa[i] & bb[i]) | (aa[i] & c) | (bb[i] & c)){
                ret.push_back(0);
                c = 1;
            } else if(!aa[i] & !bb[i] & !c){
                ret.push_back(0);
                c = 0;
            } else {
                ret.push_back(1);
                c = 0;
            }
        }
        for(int i=bb.size(); i<aa.size(); ++i){
            if(c & aa[i]){
                ret.push_back(0);
                c = 1;
            } else if(c | aa[i]){
                ret.push_back(1);
                c = 0;
            } else {
                ret.push_back(0);
                c = 0;
            }
        }
        if(c == 1) ret.push_back(1);
        int rett = Bits2Int(ret);
        return rett;
    }

public:
    vector<int> Int2Bits(int a){
        vector<int> ret;
        while(a){
            ret.push_back(a%2);
            a = a/2;
        }
        //cout << endl;
        //for(auto i : ret) cout << i << " ";
        return ret; //small is small index;
    }
    
    int Bits2Int(vector<int> &a){
        int ret = 0;
        int size = a.size();
        //int p = 1;
        for(int i=0; i<size; ++i){
            ret += a[i]*pow(2,i);
            //p = p*2;
        }
        //cout << endl;
        //for(auto i : a) cout << i << " ";
        return ret;
    }
};

int main(){
    int a = 15;
    int b = 92;
    Solution S;
    cout << S.getSum(a, b) << endl;

}
