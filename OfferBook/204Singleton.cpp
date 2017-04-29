/*Problem: realize a singleton
 *Solution: 静态局部变量的使用，静态局部变量只会初始化一遍，生存期是整个函数
 */

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution instance;
        return &instance;
    }

private:
    Solution(){};
    Solution(const Solution &);
    Solution &operator = (const Solution &);
};
