/**
 * 45. 扑克牌顺子
 * https://www.nowcoder.com/questionTerminal/762836f4d43d43ca9deb273b3de8e1f4
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty()) {
            return false;
        }

        sort(numbers.begin(), numbers.end());

        int zerocnt = 0;

        for (size_t i = 0; i < numbers.size() - 1; ++i) {
            if (numbers[i] == 0) {
                ++zerocnt;
            } else if (numbers[i] == numbers[i + 1]) {
                return false;
            } else {
                zerocnt -= (numbers[i + 1] - numbers[i]) - 1;
            }
        }

        return zerocnt >= 0;
    }
};
