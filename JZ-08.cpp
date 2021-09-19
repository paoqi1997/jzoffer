/**
 * 8. 跳台阶
 * https://www.nowcoder.com/questionTerminal/8c82a5b80378478f9484d87d1c5f12a4
 */

#include <vector>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number == 0) {
            return 0;
        } else if (number == 1) {
            return 1;
        } else if (number == 2) {
            return 2;
        } else {
            return jumpFloor(number - 1) + jumpFloor(number - 2);
        }
    }
    int jumpFloor2(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
