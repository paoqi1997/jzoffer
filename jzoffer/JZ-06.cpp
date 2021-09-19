/**
 * 6. 旋转数组的最小数字
 * https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
 */

#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        size_t low = 0, high = rotateArray.size() - 1;

        while (low < high) {
            size_t middle = (low + high) / 2;

            // [2, 3, 4, 5, 6]
            // 最小数字在 middle 的左边
            if (rotateArray[middle] < rotateArray[high]) {
                high = middle;
            }
            // [4, 5, 6, 2, 3]
            // 最小数字在 middle 的右边
            else if (rotateArray[middle] > rotateArray[high]) {
                low = middle + 1;
            }
            // [1, 0, 1, 1, 1] | [1, 1, 1, 0, 1]
            // 不确定
            else {
                ++low;
            }
        }

        return rotateArray[low];
    }
};
