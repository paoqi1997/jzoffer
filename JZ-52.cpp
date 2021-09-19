/**
 * 52. 正则表达式匹配
 * https://www.nowcoder.com/questionTerminal/28970c15befb4ff3a264189087b99ad4
 */

#include <string>

using namespace std;

class Solution {
public:
    bool match(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        // 匹配第一个字符
        bool m = !s.empty() && (p[0] == s[0] || p[0] == '.');

        // 进一步地有'*'
        if (p.length() >= 2 && p[1] == '*') {
            // 若匹配0个元素，p需要往后走2格，否则继续匹配s
            return match(s, p.substr(2)) || (m && match(s.substr(1), p));
        }
        // 没有'*'，继续往下走
        else {
            return m && match(s.substr(1), p.substr(1));
        }
    }
};
