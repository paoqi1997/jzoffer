/**
 * 12. 数值的整数次方
 * https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00
 */

#include <cmath>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        return pow(base, exponent);
    }

    double Power_v2(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        }

        double res = 1;
        int exp = exponent;

        if (exponent < 0) {
            exponent = -exponent;
        }

        // 引入快速幂思想
        while (exponent != 0) {
            if (exponent & 1 == 1) {
                res *= base;
            }

            base *= base;
            exponent >>= 1;
        }

        return exp >= 0 ? res : (1 / res);
    }
};
