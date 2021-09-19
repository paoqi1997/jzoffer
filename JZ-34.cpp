/**
 * 34. 第一个只出现一次的字符位置
 * https://www.nowcoder.com/questionTerminal/1c82e8cf713b4bbeb2a5b31cf5b0417c
 */

#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string s) {
        map<char, pair<int, int>> dict;

        for (size_t i = 0; i < s.length(); ++i) {
            if (dict.find(s[i]) == dict.end()) {
                dict[s[i]] = make_pair(i, 1);
            } else {
                ++dict[s[i]].second;
            }
        }

        int index = INT_MAX;

        for (auto& kv : dict) {
            auto& pr = kv.second;
            if (pr.second == 1) {
                index = min(pr.first, index);
            }
        }

        if (index == INT_MAX) {
            return -1;
        } else {
            return index;
        }
    }

    int FirstNotRepeatingChar_v2(string s) {
        map<char, int> counter;

        for (size_t i = 0; i < s.length(); ++i) {
            ++counter[s[i]];
        }

        for (size_t i = 0; i < s.length(); ++i) {
            if (counter[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
