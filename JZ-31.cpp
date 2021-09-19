/**
 * 31. 整数中1出现的次数（从1到n整数中1出现的次数）
 * https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6
 */

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int cnt = 0;

        for (int i = 1; i <= n; ++i) {
            string s = to_string(i);
            cnt += count(s.begin(), s.end(), '1');
        }

        return cnt;
    }

    int NumberOf1Between1AndN_Solution_v2(int n) {
        int cnt = 0;

        for (int i = 1; i <= n; ++i) {
            int num = i;

            while (num > 0) {
                if (num % 10 == 1) {
                    ++cnt;
                }

                num /= 10;
            }
        }

        return cnt;
    }
};
