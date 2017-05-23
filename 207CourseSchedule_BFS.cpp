/* 课程规划问题：给定课程的数量和修课的先后关系，求是否是合法的顺序
 * Solution:就是检测组成的graph有没有环
 * 1. BFS : 检测入度为0的节点，如果不存在，有环； 存在（标记该点入度为-1，表示已访问），同时减少这个点邻居的入度值1，直到判断所有的点
 * 2. DFS ：遍历每一个点，对于从某个节点开始的DFS，如果访问了已经访问过的点，有环，如果访问了所有的点都没有，则无环。所以这里维护两个
 * 数组，一个记录哪些节点访问过，一个记录当前DFS访问过的节点（看看是否有访问过的之前）。
 *
 * 同时，需要建图，使用vector<unordered_set<int>> 来进行记录吧，表示index 连接的边。
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph graph = constructGraph(numCourses, prerequisites);
        vector<int> in_deg = inDegree(graph); 
        for(int i=0; i<numCourses; ++i){
            int j = 0;
            for(; j<numCourses; ++j){
                if(in_deg[j] == 0) break;
            }
            if(j == numCourses) return false; //can not find a node which in_degree is 0.
            in_deg[j] = -1; //avoid visited again.
            for(int end : graph[j]){
                in_deg[end] --; //every end node decrease 1.
            }
        }
        return true;
    }
private:
    typedef vector<unordered_set<int>> Graph;
    Graph constructGraph(int numCourses, vector<pair<int,int>> &prerequisites){
        Graph graph(numCourses);
        for(auto edge : prerequisites){
            int start = edge.first;
            int end = edge.second;
            graph[start].insert(end);
        }
        return graph;
    }

    vector<int> inDegree(Graph &graph){
        vector<int> in_deg(graph.size());
        for(auto edges : graph){
            for(int end : edges){
                in_deg[end]++;
            }
        }
        return in_deg;
    }
};
