/**
 * 29. 最小的K个数
 * https://www.nowcoder.com/questionTerminal/6a296eb82cf844ca8539b57c23e6e9bf
 */

#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.empty() || k <= 0 || k > input.size()) {
            return vector<int>{};
        }

        vector<int> box;
        priority_queue<int, vector<int>, greater<int>> q;

        for (int ele : input) {
            q.emplace(ele);
        }

        while (k-- > 0) {
            box.emplace_back(q.top());
            q.pop();
        }

        return box;
    }

    vector<int> GetLeastNumbers_Solution_v2(vector<int> input, int k) {
        size_t n = input.size();

        for (int i = n / 2 - 1; i >= 0; --i) {
            make_heap(input, i, n);
        }

        for (size_t i = 1; i < k + 1; ++i) {
            // 交换堆顶元素和末尾元素，使最小元素沉至数组末端
            swap(input[0], input[n - i]);
            make_heap(input, 0, n - i);
        }

        vector<int> res(input.begin() + n - k, input.end());

        return res;
    }

    void make_heap(vector<int>& m, int rootIndex, int n) {
        int rootVal = m[rootIndex];
        size_t leafIndex = rootIndex * 2 + 1;

        while (leafIndex < n) {
            if (leafIndex + 1 < n && m[leafIndex] > m[leafIndex + 1]) {
                ++leafIndex;
            }

            if (rootVal > m[leafIndex]) {
                m[rootIndex] = m[leafIndex];
                rootIndex = leafIndex, leafIndex = rootIndex * 2 + 1;
            } else {
                break;
            }
        }

        m[rootIndex] = rootVal;
    }
};
