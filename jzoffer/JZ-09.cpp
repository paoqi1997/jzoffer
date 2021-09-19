/**
 * 9. 变态跳台阶
 * https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
 */

class Solution {
public:
    int jumpFloorII(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            int cnt = 1;
            for (int i = 1; i < n; ++i) {
                cnt += jumpFloorII(n - i);
            }
            return cnt;
        }
    }
};
