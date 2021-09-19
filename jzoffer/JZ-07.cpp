/**
 * 7. 斐波那契数列
 * https://www.nowcoder.com/questionTerminal/c6c7742f5ba7442aada113136ddea0c3
 */

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }

        int x1 = 1, x2 = 1, r;

        for (int i = 3; i <= n; ++i) {
            r = x1 + x2;
            x1 = x2, x2 = r;
        }

        return r;
    }
};
