/**
 * 64. 滑动窗口的最大值
 * https://www.nowcoder.com/questionTerminal/1624bc35a45c42c0bc17d17fa0cba788
 */

#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;

        // {2, 3, 4, 2, 6, 2, 5, 1}, 3
        if (num.empty() || size == 0 || num.size() < size) {
            return res;
        }

        deque<int> q;

        // {[2, 3, 4], 2, 6, 2, 5, 1}, 4
        // {2, [3, 4, 2], 6, 2, 5, 1}, 4
        // {2, 3, [4, 2, 6], 2, 5, 1}, 6
        // {2, 3, 4, [2, 6, 2], 5, 1}, 6
        // {2, 3, 4, 2, [6, 2, 5], 1}, 6
        // {2, 3, 4, 2, 6, [2, 5, 1]}, 5

        for (size_t i = 0; i < num.size(); ++i) {
            // 队列会一直T掉比当前值小的末尾元素
            // [6, 2, 1] <= 4 -> [6, 4]
            while (!q.empty() && num[q.back()] < num[i]) {
                q.pop_back();
            }

            // 放进来，其实队列放的就是各个最大值的索引
            q.push_back(i);

            // 如果当前行进到5，而窗口值为3，那么索引2及之前的都不能要了
            if (q.front() + size <= i) {
                q.pop_front();
            }

            // 如果窗口值为3，那么i至少要到2才能形成一个窗口
            if (i + 1 >= size) {
                res.emplace_back(num[q.front()]);
            }
        }

        return res;
    }
};
