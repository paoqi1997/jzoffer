/**
 * 66. 机器人的运动范围
 * https://www.nowcoder.com/questionTerminal/6e5207314b5241fb83f2329e89fdecc8
 */

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if (threshold <= 0) {
            return 0;
        }

        int **grid = new int*[rows];

        for (int i = 0; i < rows; ++i) {
            grid[i] = new int[cols];
        }

        int res = 0;

        dfs(0, 0, threshold, rows, cols, res, grid);

        return res;
    }

    void dfs(int row, int col, int threshold, int maxrow, int maxcol, int& res, int **grid) {
        if (row < 0 || row >= maxrow || col < 0 || col >= maxcol) {
            return;
        }
        // 已经进入过该格子
        if (grid[row][col] == 1 || digitSum(row) + digitSum(col) > threshold) {
            return;
        }

        grid[row][col] = 1;
        res += 1;

        dfs(row - 1, col, threshold, maxrow, maxcol, res, grid); // 上
        dfs(row + 1, col, threshold, maxrow, maxcol, res, grid); // 下
        dfs(row, col - 1, threshold, maxrow, maxcol, res, grid); // 左
        dfs(row, col + 1, threshold, maxrow, maxcol, res, grid); // 右
    }

    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
};
