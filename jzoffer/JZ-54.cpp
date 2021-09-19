/**
 * 54. 字符流中第一个不重复的字符
 * https://www.nowcoder.com/questionTerminal/00de97733b8e4f97a3fb5c680ee10720
 */

#include <climits>
#include <map>
#include <utility>

using namespace std;

class Solution
{
public:
    void Insert(char ch) {
        if (m.find(ch) == m.end()) {
            m[ch] = make_pair(pos, 1);
        } else {
            ++m[ch].second;
        }

        ++pos;
    }

    char FirstAppearingOnce() {
        char ch = '#';
        size_t minpos = INT_MAX;

        for (auto it = m.begin(); it != m.end(); ++it) {
            auto& pr = it->second;
            if (pr.second > 1) {
                continue;
            }

            if (minpos > pr.first) {
                minpos = pr.first;
                ch = it->first;
            }
        }

        return ch;
    }
private:
    size_t pos;
    map<char, pair<size_t, size_t>> m;
};
