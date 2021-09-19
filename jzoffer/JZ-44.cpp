/**
 * 44. 翻转单词序列
 * https://www.nowcoder.com/questionTerminal/3194a4f4cf814f63919d0790578d51f3
 */

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string ReverseSentence(string s) {
        if (s.empty()) {
            return s;
        }

        size_t i = 0, length = s.length();

        while (i < length && s[i] == ' ') ++i;

        // 都为空格就直接返回
        if (i == length) {
            return s;
        }

        // 逐个读取
        istringstream is(s);

        vector<string> box;
        string str;

        while (is >> str) {
            box.emplace_back(str);
        }

        // 反转
        reverse(box.begin(), box.end());

        // 逐个纳入
        ostringstream os;

        for (size_t i = 0; i < box.size() - 1; ++i) {
            os << box[i] << ' ';
        }

        os << box.back();

        return os.str();
    }

    string ReverseSentence_v2(string s) {
        string res, tmp;

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                res = " " + tmp + res;
                tmp.clear();
            } else {
                tmp += s[i];
            }
        }

        return tmp + res;
    }
};
