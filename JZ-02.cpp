/**
 * 2. 替换空格
 * https://www.nowcoder.com/questionTerminal/0e26e5551f2b489b9f58bc83aa4b6c68
 */

#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                res.append(1, s[i]);
            } else {
                res.append("%20");
            }
        }

        return res;
    }
};
