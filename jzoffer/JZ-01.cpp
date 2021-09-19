/**
 * 1. 二维数组中的查找
 * https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        // 从左下角开始查找
        int row = array.size() - 1;
        size_t col = 0;

        while (row >= 0 && col < array[0].size()) {
            if (target == array[row][col]) {
                return true;
            }
            // 在上方
            else if (target < array[row][col]) {
                --row;
            }
            // 在右方
            else {
                ++col;
            }
        }

        return false;
    }
};
