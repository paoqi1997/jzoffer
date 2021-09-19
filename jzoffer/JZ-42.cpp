/**
 * 42. 和为S的两个数字
 * https://www.nowcoder.com/questionTerminal/390da4f7a00f44bea7c2f3d19491311b
 */

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if (array.empty()) {
            return vector<int>{};
        }

        vector<int> res(2);

        int product = INT_MAX;

        size_t i = 0, j = array.size() - 1;

        while (i < j) {
            if (array[i] + array[j] > sum) {
                --j;
            } else if (array[i] + array[j] < sum) {
                ++i;
            } else {
                if (product > array[i] * array[j]) {
                    product = array[i] * array[j];
                    res[0] = array[i];
                    res[1] = array[j];
                }

                --j;
            }
        }

        if (product == INT_MAX) {
            return vector<int>{};
        } else {
            return res;
        }
    }
};
