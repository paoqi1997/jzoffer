/**
 * 46. 孩子们的游戏(圆圈中最后剩下的数)
 * https://www.nowcoder.com/questionTerminal/f78a359491e64a50bce2d89cff857eb6
 */

#include <vector>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n == 0) {
            return -1;
        }

        vector<int> children(n);

        for (int i = 0; i < n; ++i) {
            children[i] = i;
        }

        int i = 0, size = n;

        while (n-- > 1) {
            // 本轮报数
            int cnt = 0;

            while (cnt < m) {
                if (i == size) {
                    i = 0;
                }

                if (children[i] != -1) {
                    if (++cnt == m) {
                        break;
                    }
                }

                ++i;
            }

            children[i] = -1;
        }

        for (int child : children) {
            if (child != -1) {
                return child;
            }
        }

        return -1;
    }

    int LastRemaining_Solution_v2(int n, int m) {
        if (n == 0) {
            return -1;
        }

        vector<int> children(n);

        // cnt为本轮报数
        int i = -1, size = n, cnt = 0;

        while (n > 0) {
            if (++i == size) {
                i = 0;
            }

            if (children[i] == -1) {
                continue;
            }

            if (++cnt == m || cnt == m % n) {
                children[i] = -1;
                --n;
                cnt = 0;
            }
        }

        return i;
    }

    int LastRemaining_Solution_v3(int n, int m) {
        if (n == 0) {        // f(0) = -1
            return -1;
        } else if (n == 1) { // f(1) = 0
            return 0;
        } else {             // f(n) = (f(n - 1) + m) % n
            return (LastRemaining_Solution_v3(n - 1, m) + m) % n;
        }
    }
};
