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
        vector<bool> global(numCourses, false),  cur(numCourses, false);
        for(int i=0; i<numCourses; ++i){
            if(global[i])continue;
            if(dfsCycle(graph, i, global, cur)) return false; //have cycle
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

    //if there is a cycle, return true.
    bool dfsCycle(Graph &graph, int node, vector<bool> &global, vector<bool> &cur){
        //cur to remember nodes visited in this dfs, global to remember the nodes have been visited now.
        if(global[node]) return false;  //have been visited before, no cycle.
        global[node] = cur[node] = true; //now visit it
        auto ends = graph[node]; //the node-->ends
        for(int end : ends){
            if(cur[end] || dfsCycle(graph, end, global, cur)) return true; //if end is visited in this cur OR the end node has a cycle.
        }
        cur[node] = false;  //make cur[node] to NOT visited for next dfs.
        return false;
    }
};
