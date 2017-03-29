/*问题：给定一组非重叠的时间区间，插入一个新的区段，需要merge。
 * 解法：既然已经排序，则该序列是递增，求解新区间的start，end所在的位置，然后将这两个位置
 * 间的区间合并。注意的地方是，求解start适合intervals[i].end比较，因为start只会影响到到start_index，
 * 然后记录该index,并update star_index即可，求解end适合intervas[i].start比较，理由同上
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int start = newInterval.start;
        int end = newInterval.end;
        int size = intervals.size();
        int i = 0;
        while(i < size && start > intervals[i].end) ++i; //compares with next end;
        if(i == size){
            intervals.push_back(newInterval);
            return intervals;
        }
        int start_new = min(start, intervals[i].start);
        int start_index = i;
        while(i < size && end >= intervals[i].start) ++i; //compared with next start;
        int end_new = max(end, intervals[i-1].end);
        int end_index = i-1;
        Interval unions(start_new, end_new);
        auto iter = intervals.erase(intervals.begin()+start_index, intervals.begin()+end_index+1); //return the iterator followed last erased
        intervals.insert(iter, unions); //insert before iter.
        return intervals;
    }
};

void print(vector<Interval> ret){
    for(auto i : ret){
        cout << i.start << "--" << i.end << " ";
    }
    cout << endl;
}

int main(){
    freopen("57test.txt", "r", stdin);
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
        int s,e; cin >> s >> e;
        Interval newInterval(s,e);
        auto ret = Sol.insert(input, newInterval);
        print(ret);
    }
}

