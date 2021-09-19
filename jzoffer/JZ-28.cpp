/**
 * 28. 数组中出现次数超过一半的数字
 * https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
 */

#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        }

        int num = numbers[0], cnt = 1;

        for (size_t i = 1; i < numbers.size(); ++i) {
            // 由于 --cnt 的存在，cnt 在这里并不是 num 的出现次数
            if (numbers[i] == num) {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    num = numbers[i];
                    cnt = 1;
                }
            }
        }

        cnt = 0;

        for (int n : numbers) {
            if (n == num) {
                ++cnt;
            }
        }

        if (cnt > numbers.size() / 2) {
            return num;
        } else {
            return 0;
        }
    }
};
