/**
 * 21. 栈的压入、弹出序列
 * https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106
 */

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 给入栈队列和出栈队列设置两个哨兵，其索引分别为i和j，然后引入一个辅助栈stk。
     *
     * 在一次操作中，辅助栈从入栈队列中取走哨兵i对应的值并将其压栈，随后栈顶元素与出栈序列中哨兵j对应的值进行比较，
     * 若相等，则应出栈，同时哨兵j前进；否则哨兵i前进，继续压栈。
     *
     * 如果最后辅助栈为空，则出栈队列是入栈队列对应的一个弹出序列，否则不是。
     */
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty()) {
            return false;
        }

        stack<int> stk;

        // pushV -> 1 2 3 4 5
        //  popV -> 4 5 3 2 1 (true)
        //       -> 4 3 5 1 2 (false)
        for (size_t i = 0, j = 0; i < pushV.size(); ++i) {
            stk.push(pushV[i]);
            while (!stk.empty() && stk.top() == popV[j]) {
                stk.pop();
                ++j;
            }
        }

        return stk.empty();
    }
};
