/**
 * 27. 字符串的排列
 * https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7
 */

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string s) {
        vector<string> box;

        if (!s.empty()) {
            __permutation(box, s, 0);
            sort(box.begin(), box.end());
        }

        return box;
    }

    void __permutation(vector<string>& box, string s, size_t index) {
        if (index == s.length() - 1) {
            if (find(box.begin(), box.end(), s) == box.end()) {
                box.emplace_back(s);
            }
        }

        for (size_t i = index; i < s.length(); ++i) {
            swap(s[i], s[index]);
            __permutation(box, s, index + 1);
            swap(s[i], s[index]);
        }
    }

    vector<string> Permutation2(string s) {
        if (s.empty()) {
            return vector<string>{};
        }

        vector<string> box;

        do {
            box.emplace_back(s);
        } while (next_permutation(s.begin(), s.end()));

        return box;
    }
};
