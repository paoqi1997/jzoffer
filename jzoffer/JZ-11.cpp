/**
 * 11. 二进制中1的个数
 * https://www.nowcoder.com/questionTerminal/8ee967e43c2c4ec193b040ea7fbb10b8
 */

#include <bitset>

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        int cnt = 0;

        // 15
        // 1111 & 1110 -> 1110
        // 1110 & 1101 -> 1100
        // 1100 & 1011 -> 1000
        // 1000 & 0111 -> 0000
        while (n) {
            n &= n - 1;
            ++cnt;
        }

        return cnt;
    }
    int NumberOf1_v2(int n) {
        return bitset<32>(n).count();
    }
};
