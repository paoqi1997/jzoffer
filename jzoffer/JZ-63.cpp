/**
 * 63. 数据流中的中位数
 * https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1
 */

#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    void Insert(int num) {
        // 若当前个数为偶数，将元素放入小根堆，再将小根堆的堆顶元素放到大根堆中
        // [2, 2] -> [2, 3] -> [3, 2]
        if (cnt++ % 2 == 0) {
            right_q.push(num);
            left_q.push(right_q.top());
            right_q.pop();
            return;
        }

        // 若当前个数为奇数，将元素放入大根堆，再将大根堆的堆顶元素放到小根堆中
        // [3, 2] -> [4, 2] -> [3, 3]
        left_q.push(num);
        right_q.push(left_q.top());
        left_q.pop();
    }

    double GetMedian() {
        if (cnt % 2 == 0) {
            // [3, 3]中的第3个和第4个元素
            return (left_q.top() + right_q.top()) / 2.0;
        } else {
            // [3, 2]中的第3个元素
            return left_q.top();
        }
    }
private:
    size_t cnt;
    priority_queue<int> left_q;                             // 大根堆，堆顶元素最大，中位数左边的数据放到这里
    priority_queue<int, vector<int>, greater<int>> right_q; // 小根堆，堆顶元素最小，中位数右边的数据放到这里
};
