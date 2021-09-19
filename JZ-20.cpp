/**
 * 20. 包含min函数的栈
 * https://www.nowcoder.com/questionTerminal/4c776177d2c04c2494f2555c9fcc1e49
 */

#include <stack>

using namespace std;

class Solution {
public:
    void push(int value) {
        stack1.push(value);
        if (stack2.empty() || stack2.top() > stack1.top()) {
            stack2.push(value);
        }
    }
    void pop() {
        if (stack2.top() == stack1.top()) {
            stack2.pop();
        }
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2; // 监视最小值的栈
};
