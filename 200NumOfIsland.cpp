/* 二维矩阵，1表示陆地，0表示water，相邻的1组成一个小岛，求小岛的数量
 * Solution： 1. 使用dfs,每次访问到1，遍历完全后变成0,,,故要修改矩阵
 * 2. 并查集，并查集在动态的问题中性能更优。
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//并查集的解决方案

class Solution{
public:
    vector<int> parent;
    vector<int> size;
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool isConnected(int x, int y){
        return find(x) == find(y);
    }

    void Union(int x, int y){
        if(find(x) == find(y)) return;
        int pa = find(x);
        int pb = find(y);
        if(size[pa] < size[pb]){
            parent[pa] = pb;
            size[pb] += size[pa];
        } else {
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }

    int numIslands(vector<vector<char>> &grid){
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m(grid.size()), n(grid[0].size());
        int count = 0;
        parent.resize(m*n);
        size.resize(m*n);
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == '1'){
                    ++count;
                    parent[i*n+j] = i*n+j;
            }
        }
        vector<pair<int,int>> dir{{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == '0'){
                    continue;
                } else {
                    for(auto d : dir){
                        int x = i+d.first;
                        int y = j+d.second;
                        if(x<0 || x>=m || y<0 || y>=n || grid[x][y] == '0') continue;

                        if(! isConnected(x*n+y, i*n+j)){
                            --count;  //cause (x,y) is neighbor of (i,j), if is not connected, Union them.
                            Union(x*n+y, i*n+j);
                        } 
                    }
                }
            }
        }
        return count;
    }

}

/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<pair<int,int>> dir{{0,1}, {0,-1}, {1,0}, {-1,0}};
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m(grid.size()), n(grid[0].size());
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, dir, i, j);
                    count ++; // here find a block of 1.
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>> & grid, vector<pair<int,int>> &dir, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == '0') return;
         grid[i][j] = '0';
        for(auto d : dir){
            dfs(grid, dir, i+d.first, j+d.second);        
        }
    }
};
*/
