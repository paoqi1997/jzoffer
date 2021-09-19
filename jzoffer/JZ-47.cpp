/**
 * 47. 求1+2+3+...+n
 * https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1
 */

class Solution {
public:
    int Sum_Solution(int n) {
        n > 1 && (n += Sum_Solution(n - 1));
        return n;
    }
};
