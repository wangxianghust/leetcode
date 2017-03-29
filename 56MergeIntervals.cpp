/*问题：给定一组时间区间，将重复的区间合并，返回最后各个独立的区间。
 * 解法：先排序，按照开始时间排序，然后依次检测后一个的开始时间与上一个的结束时间是否覆盖
 * 注意每次合并都需要update结束时间为最大即可。
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e){}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals;
        //sort(intervals.begin(), intervals.end(), cmp);
        //we can use lamda here, by c++11
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        vector<Interval> ret;
        int size = intervals.size();
        ret.push_back(intervals[0]);
        //update the ret.back().end
        for(int i=1; i<size; ++i){
            if(intervals[i].start > ret.back().end) ret.push_back(intervals[i]);
            else ret.back().end = max(ret.back().end, intervals[i].end);
        }
        return ret;
    }

public:
    static bool cmp(Interval &a, Interval &b){
        return a.start < b.start;
    }
};

void print(vector<Interval> ret){
    for(auto i : ret){
        cout << i.start << "--" << i.end << " ";
    }
    cout << endl;
}

int main(){
    freopen("56test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<Interval> input;
        for(int j=0; j<size; ++j){
            int a, b;
            cin >> a >> b;
            Interval inter(a,b);
            input.push_back(inter);
        }
        auto ret = Sol.merge(input);
        print(ret);
    }
}
