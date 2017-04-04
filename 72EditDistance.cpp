/*Problem: calculate the edit distance between two string
 *Solution: Dp,这里的distance指代的是前缀之间的距离，每个节点的值取决于上，左，左上角
 *三个方位的min
 */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size_1 = word1.size();
        int size_2 = word2.size();
        int distance[size_1+1][size_2+1];//distance means the distance between word1(size1) to word2(size2);
        for(int i=0; i<size_1+1; ++i){
            for(int j=0; j<size_2+1; ++j) distance[i][j] = 0;
        }
        //intialization
        for(int i=0; i<=size_1; ++i) distance[i][0] = i; //delete i times
        for(int j=0; j<=size_2; ++j) distance[0][j] = j; //add i times
        
        for(int i=1; i<=size_1; ++i){ //i is the prefix lenth of word1
            for(int j=1; j<=size_2; ++j){ //j is the prefix length of word2
                int cost(0);
                if(word1[i-1] != word2[j-1]) cost = 1;
                int insert_op = distance[i][j-1] + 1;
                int delete_op = distance[i-1][j] + 1; 
                int replace_op = distance[i-1][j-1] + cost;
                distance[i][j] = min( insert_op, min(delete_op, replace_op) );
            }
        }
        return distance[size_1][size_2];        
    }
};

int main(){
    freopen("72test.txt", "r", stdin);
    int total; cin >> total;
    Solution Sol;
    while(total--){
        string w1, w2;
        cin >> w1 >> w2;
        cout << Sol.minDistance(w1, w2) << endl;
    }
}
