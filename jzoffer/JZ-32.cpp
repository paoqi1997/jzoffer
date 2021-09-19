/**
 * 32. 把数组排成最小的数
 * https://www.nowcoder.com/questionTerminal/8fecd3f8ba334add803bf2a06af1b993
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), [](int x, int y){
            string s1 = to_string(x) + to_string(y);
            string s2 = to_string(y) + to_string(x);
            return s1 < s2;
        });

        string s;

        for (int n : numbers) {
            s.append(to_string(n));
        }

        return s;
    }
};
