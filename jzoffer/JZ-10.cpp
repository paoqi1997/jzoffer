/**
 * 10. 矩形覆盖
 * https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6
 */

class Solution {
public:
    /**
     * 与跳台阶原理相同，1级台阶对应1个2*1的小矩形，2级台阶对应2个2*1的小矩形，n级台阶对应n个2*1的小矩形，也就是1个2*n的大矩形。
     */
    int rectCover(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            return rectCover(n - 1) + rectCover(n - 2);
        }
    }
};
