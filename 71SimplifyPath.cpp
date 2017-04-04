/* 问题：简化文件路径，如 //-->/  /a/b/../c --> /a/c
 * 方法：先处理//，然后使用/对自字符串进行划分，主要对.和..模式的匹配。
 */

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template<class T>
void print(vector<T> ret){
    for(T i : ret) cout << i << "--";
    cout << endl;
}

class Solution {
public:

    string simplifyPath(string path){
        string ret;
        stringstream str(path);
        string one;
        vector<string> vec;
        while(std::getline(str, one, '/')){
            if(one == "" || one == ".") continue;
            else if(one == ".." && !vec.empty()) vec.pop_back();
            else if(one != "..") vec.push_back(one);
        }
        for(string s : vec) ret = ret + "/" + s;
        return ret.empty() ? "/" : ret;
    }


    //so many case, this is not a good idea.
    string simplifyPath_(string path) {
        string ret="";
        auto vec = split(path, "/");
        auto beg = vec.begin();
        //cout << vec.size() << " test" << endl;
        while(*beg == ".."){  //erasethe front .. just like case /../
            beg = vec.erase(beg);
            if(beg == vec.end()) break;
        }
       // print(vec);
        if(vec.size() == 1 || vec.size() == 0) return "/";  //For case /////
        for(beg=vec.begin(); beg!=vec.end(); ){
            if(*beg == "." || *beg == ""){
                beg = vec.erase(beg);
            } else if(*beg == ".."){
                beg = vec.erase(beg-1, beg+1); //beg-1 may over stack, but while loop has protected operation.
            } else {
                ++beg;
            }
        }   
        if(vec.empty()) return "/";
        for(string str : vec) ret = ret + "/" + str;
        return ret;
    }

private:
    vector<string> split(const string &s, const string &delim){
        vector<string> ret;
        string::size_type front = 0;
        string::size_type last = s.find_first_of(delim, front);
        while(last != string::npos){
            if(last > front){
                string tmp = s.substr(front, last-front);
                ret.push_back(tmp);
            }
            front = last+1;
            last = s.find_first_of(delim, front);
        }
        if(last > front){
            ret.push_back(s.substr(front, last-front));
        }
        //cout << "ret size : " << ret.size() << endl;
        return ret;
    }
};


int main(){
    freopen("71test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        string path; cin >> path;
        string ret = Sol.simplifyPath(path);
        cout << ret << endl;
    }
}
