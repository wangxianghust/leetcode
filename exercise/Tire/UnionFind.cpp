/*并查集的实现，此处使用并查集进行树的判断
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class DisjointSet{
    public:
        vector<int> parent;
        vector<int> rank;
    public:
        int Find(int x){
            if(parent[x] == x){
                return x;
            }
            parent[x] = Find(parent[x]);
            return parent[x];
        }

        bool Union(int a, int b, int &count){
            int pa = parent[a];
            int pb = parent[b];
            if(pa == pb) return false;
            if(rank[pa] < rank[pb]){
                parent[pa] = pb;
            } else if(rank[pa] > rank[pb]){
                parent[pb] = pa;
            } else {
                parent[pb] = pa;
                ++rank[pa];
            }
            --count; //count is the number of disjoint componet.
            return true;
        }
    public:
        bool isValid(int n, vector<pair<int,int> > &edges){
            parent.resize(n);
            rank.resize(n);
            for(int i=0; i<n; ++i){
                parent[i] = i;
            }
            int count = n;
            for(auto edge : edges){
                if(! Union(edge.first, edge.second, count)){
                    return false;
                }
            }
            return count == 1;
        }
};

int main(){
    freopen("UnionFind.txt", "r", stdin);
    int total; cin >> total;
    DisjointSet DS;
    for(int i=0; i<total; ++i){
        int node_num; cin >> node_num;
        int edge_num; cin >> edge_num;
        vector<pair<int,int> > edges;
        for(int j=0; j<edge_num; ++j){
            int a, b; cin >> a >> b;
            edges.push_back(make_pair(a,b));
        }
        bool ret = DS.isValid(node_num, edges);
        cout << ret << endl;
    }
}
