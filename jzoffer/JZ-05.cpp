/**
 * 5. 用两个栈实现队列
 * https://www.nowcoder.com/questionTerminal/54275ddae22f475981afa2244dd448c6
 */

#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int node;
        // 若 stack1 为 [1, 2, 3, 4]，stack2 为空
        if (stack2.empty()) {
            // 依次弹出4、3、2、1
            while (!stack1.empty()) {
                node = stack1.top();
                stack1.pop();
                stack2.push(node);
            }
        }

        // 此时1在栈顶，弹出之
        node = stack2.top();
        stack2.pop();
        return node;
    }
private:
    stack<int> stack1; // 入队列
    stack<int> stack2; // 出队列
};
