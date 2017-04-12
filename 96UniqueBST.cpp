/*Problem: 给定1~n共计n个数，求这些数字可以组成的二叉树个数
 * Solution：组合问题，假设我们选定一个x为root, 则ret += ret[x-1] * ret[n-x]
 * 分别为左子树和右子树个数的乘积
 */

class Solution {
public:
    int numTrees(int n) {
        int ret[n+1];
        for(int i=0; i<n+1; ++i) ret[i] = 0;
        ret[0] = 1;
        ret[1] = 1;
        if(n < 2) return ret[n];
        for(int i=2; i<=n; ++i){
            for(int j=1; j<=i; ++j)
                ret[i] += ret[j-1]*ret[i-j];
        }
        return ret[n];
    }
};

int main(){
    //AC
}
