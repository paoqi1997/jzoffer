/**
 * 51. 构建乘积数组
 * https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);

        for (size_t i = 1; i < A.size(); ++i) {
            B[i] = B[i - 1] * A[i - 1];
        }

        int tmp = 1;

        for (int i = A.size() - 2; i >= 0; --i) {
            tmp *= A[i + 1];
            B[i] *= tmp;
        }

        return B;
    }
};
