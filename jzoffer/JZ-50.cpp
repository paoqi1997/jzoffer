/**
 * 50. 数组中重复的数字
 * https://www.nowcoder.com/questionTerminal/6fe361ede7e54db1b84adc81d09d8524
 */

#include <vector>

using namespace std;

class Solution {
public:
    int duplicate(vector<int>& numbers) {
        if (numbers.empty()) {
            return -1;
        }

        vector<int> box(numbers.size());

        for (int number : numbers) {
            if (++box[number] > 1) {
                return number;
            }
        }

        return -1;
    }
};
