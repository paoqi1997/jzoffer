/**
 * 13. 调整数组顺序使奇数位于偶数前面
 * https://www.nowcoder.com/questionTerminal/ef1f53ef31ca408cada5093c8780f44b
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        stable_sort(array.begin(), array.end(), [](int x, int y){
            return x % 2 && !(y % 2);
        });
        return array;
    }

    vector<int> reOrderArray_v2(vector<int>& array) {
        // 第k个奇数的索引
        int k = -1;

        for (size_t i = 0; i < array.size(); ++i) {
            // array[i] 为奇数
            if (array[i] & 1 == 1) {
                ++k;

                int tmp = array[i];

                for (size_t j = i; j > k; --j) {
                    array[j] = array[j - 1];
                }

                // 将 array[i] 移到 array[k] 的位置
                array[k] = tmp;
            }
        }

        return array;
    }
};
