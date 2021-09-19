/**
 * 43. 左旋转字符串
 * https://www.nowcoder.com/questionTerminal/12d959b108cb42b1ab72cef4d36af5ec
 */

#include <string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string s, int n) {
        if (s.empty()) {
            return s;
        }

        size_t length = s.length();

        int num = n % length;

        string res;

        for (int i = 0; i < length - num; ++i) {
            res.append(1, s[num + i]);
        }
        for (int i = 0; i < num; ++i) {
            res.append(1, s[i]);
        }

        return res;
    }
};
