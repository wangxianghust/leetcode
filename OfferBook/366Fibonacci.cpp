/* Problem: Fibonacci
 */

#include <iostream>

using namespace std;

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int first = 0;
        int second = 1;
        if(n == 1) return first;
        if(n == 2) return second;
        for(int i=3; i<=n; ++i){
            int tmp = first + second;
            first = second;
            second = tmp;
        }
        return second;
    }
};

int main(){
    Solution Sol;
    cout<< Sol.fibonacci(6) << endl;
}

