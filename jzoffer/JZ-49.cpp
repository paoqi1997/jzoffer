/**
 * 49. 把字符串转换成整数
 * https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e
 */

#include <cctype>
#include <climits>
#include <string>

using namespace std;

class Solution {
public:
    int StrToInt(string s) {
        if (s.length() == 0) {
            return 0;
        }

        for (char c : s) {
            if (isalpha(c)) {
                return 0;
            }
        }

        size_t i = 0, length = s.length();

        while (i < length && s[i] == ' ') {
            ++i;
        }

        int res = 0;

        bool flag = false;
        if (s[i] != '+') {
            if (s[i] == '-') {
                flag = true;
            } else if (!isdigit(s[i])) {
                return 0;
            } else {
                res = s[i] - '0';
            }
        }

        ++i;

        for (; i < length; ++i) {
            if (!isdigit(s[i])) {
                break;
            } else {
                int v = s[i] - '0';
                if (res > (INT_MAX - v) / 10) {
                    return flag ? INT_MIN : INT_MAX;
                }
                res = res * 10 + v;
            }
        }

        if (flag) {
            res = -res;
        }

        return res;
    }
};
