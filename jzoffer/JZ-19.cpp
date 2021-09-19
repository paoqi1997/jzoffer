/**
 * 19. 顺时针打印矩阵
 * https://www.nowcoder.com/questionTerminal/9b4c81a02cd34f76be2659fa0d54342a
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int row = matrix.size(), col = matrix[0].size();

        vector<int> vec;
        int circle = (min(row, col) + 1) / 2;

        for (int i = 0; i < circle; ++i) {
            // 上方
            for (int c = i; c < col - i; ++c) {
                vec.push_back(matrix[i][c]);
            }
            // 右方
            for (int r = i + 1; r < row - i; ++r) {
                vec.push_back(matrix[r][col - i - 1]);
            }
            // 下方
            if (i < row - i - 1) {
                for (int c = col - i - 2; c >= i; --c) {
                    vec.push_back(matrix[row - i - 1][c]);
                }
            }
            // 左方
            if (i < col - i - 1) {
                for (int r = row - i - 2; r >= i + 1; --r) {
                    vec.push_back(matrix[r][i]);
                }
            }
        }

        return vec;
    }
};
