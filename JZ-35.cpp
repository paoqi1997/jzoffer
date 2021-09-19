/**
 * 35. 数组中的逆序对
 * https://www.nowcoder.com/questionTerminal/96bd6684e04a44eb80e6a68efc0ec6c5
 */

#include <vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int res = 0;

        vector<int> tmp(data.size());

        mergesort(data, tmp, 0, data.size() - 1, res);

        return res;
    }

    void mergesort(vector<int>& data, vector<int>& tmp, int low, int high, int& res) {
        if (low >= high) {
            return;
        }

        int middle = low + (high - low) / 2;

        mergesort(data, tmp, low, middle, res);
        mergesort(data, tmp, middle + 1, high, res);

        merge(data, tmp, low, middle, high, res);
    }

    void merge(vector<int>& data, vector<int>& tmp, int low, int middle, int high, int& res) {
        int i = low, j = middle + 1, pos = 0;

        while (i <= middle && j <= high) {
            if (data[i] <= data[j]) {
                tmp[pos++] = data[i++];
            } else {
                tmp[pos++] = data[j++];
                res += (middle - i + 1);
                res %= 1000000007;
            }
        }

        while (i <= middle) {
            tmp[pos++] = data[i++];
        }
        while (j <= high) {
            tmp[pos++] = data[j++];
        }

        for (i = low, pos = 0; i <= high; ++i, ++pos) {
            data[i] = tmp[pos];
        }
    }
};
