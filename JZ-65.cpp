/**
 * 65. 矩阵中的路径
 * https://www.nowcoder.com/questionTerminal/2a49359695a544b8939c77358d29b7e6
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<char>>& matrix, string word) {
        if (matrix.empty() || word.empty()) {
            return false;
        }

        int rows = matrix.size(), cols = matrix[0].size();

        vector<vector<bool>> grid(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (judge(i, j, rows, cols, matrix, 0, word, grid)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool judge(int row, int col, int maxrow, int maxcol, vector<vector<char>>& matrix, int idx, string word, vector<vector<bool>>& grid) {
        if (idx == word.length()) {
            return true;
        }

        if (row < 0 || row >= maxrow || col < 0 || col >= maxcol) {
            return false;
        }

        // 已经进入过该格子或者字符不对应
        if (grid[row][col] || word[idx] != matrix[row][col]) {
            return false;
        }

        grid[row][col] = true;

        bool res = false;
        res = res || judge(row - 1, col, maxrow, maxcol, matrix, idx + 1, word, grid); // 上
        res = res || judge(row + 1, col, maxrow, maxcol, matrix, idx + 1, word, grid); // 下
        res = res || judge(row, col - 1, maxrow, maxcol, matrix, idx + 1, word, grid); // 左
        res = res || judge(row, col + 1, maxrow, maxcol, matrix, idx + 1, word, grid); // 右

        grid[row][col] = false;

        return res;
    }
};
