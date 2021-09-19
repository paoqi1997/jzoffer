/**
 * 53. 表示数值的字符串
 * https://www.nowcoder.com/questionTerminal/e69148f8528c4039ad89bb2546fd4ff8
 */

#include <string>

using namespace std;

class Solution {
public:
    bool isNumeric(string s) {
        bool sign = false, decimal = false, hasE = false;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (i == s.length() - 1) {
                    return false;
                }

                if (hasE) {
                    return false;
                }

                hasE = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (sign && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }

                if (!sign && i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }

                sign = true;
            } else if (s[i] == '.') {
                if (hasE || decimal) {
                    return false;
                }

                decimal = true;
            } else if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }

        return true;
    }
};
