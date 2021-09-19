/**
 * 37. 数字在排序数组中出现的次数
 * https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2
 */

#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty()) {
            return 0;
        } else if (data.size() == 1) {
            return data[0] == k ? 1 : 0;
        }

        size_t low = 0, high = data.size() - 1;

        if (data[low] > k || data[high] < k) {
            return 0;
        }

        while (low < high) {
            size_t middle = (low + high) / 2;

            if (data[middle] < k) {
                low = middle;
            } else if (data[middle] > k) {
                high = middle;
            }

            if (data[low] < k) {
                ++low;
            }
            if (data[high] > k) {
                --high;
            }

            if (data[low] == k && data[high] == k) {
                return high - low + 1;
            }
        }

        return 0;
    }
};
