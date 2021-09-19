/**
 * 67. 剪绳子
 * https://www.nowcoder.com/questionTerminal/57d85990ba5b440ab888fc72b0751bf8
 */

#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 总长度至少为2且至少剪为2段
     */
    int cutRope(int number) {
        // 以下是总长度小于4的绳子
        if (number == 2) {
            return 1;
        } else if (number == 3) {
            return 2;
        }

        // 以下是总长度不小于4的绳子
        int *products = new int[number + 1];

        // 4在这里就是总长度，乘积最大即2*2为4
        // 而 1-3 是被剪成的小绳子，为使乘积最大也不应再剪
        for (int i = 1; i <= 4; ++i) {
            products[i] = i;
        }

        // 以5为例，讨论被剪为 (1, 4), ..., (4, 1) 的情况
        for (int i = 5; i <= number; ++i) {
            for (int j = 1; j < i; ++j) {
                products[i] = max(products[i], j * products[i - j]);
            }
        }

        return products[number];
    }
};
