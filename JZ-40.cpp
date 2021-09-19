/**
 * 40. 数组中只出现一次的数字
 * https://www.nowcoder.com/questionTerminal/389fc1c3d3be4479a154f63f495abff8
 */

#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        vector<int> res{0, 0};

        int x = array[0];
        // 由于相同数字异或的结果为0，x最终为只出现一次的数字异或的结果
        for (size_t i = 1; i < array.size(); ++i) {
            x ^= array[i];
        }

        int d = 1;
        // 确认在哪一位相异
        while ((d & x) == 0) {
            d <<= 1;
        }

        for (int ele : array) {
            if ((ele & d) == 0) {
                res[0] ^= ele;
            } else {
                res[1] ^= ele;
            }
        }

        if (res[0] > res[1]) {
            swap(res[0], res[1]);
        }

        return res;
    }
};
