/**
 * 23. 二叉搜索树的后序遍历序列
 * https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return false;
        } else {
            // 对于二叉搜索树的后序遍历序列来说，最后一个元素对应于根节点
            size_t rootIndex = sequence.size() - 1;

            while (rootIndex) {
                // 前面的元素分为两部分
                size_t i = 0;

                // 第一部分的元素均小于根节点
                while (sequence[i] < sequence[rootIndex]) ++i;
                // 第二部分的元素均大于根节点
                while (sequence[i] > sequence[rootIndex]) ++i;

                if (i == rootIndex) {
                    --rootIndex;
                } else {
                    return false;
                }
            }

            return true;
        }
    }
};
