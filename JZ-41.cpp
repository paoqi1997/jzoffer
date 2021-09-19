/**
 * 41. 和为S的连续正数序列
 * https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> res;

        vector<int> box;

        for (int i = 1; i <= sum / 2; ++i) {
            int mysum = 0;

            for (int j = i; j <= sum; ++j) {
                mysum += j;

                if (mysum == sum) {
                    for (int k = i; k <= j; ++k) {
                        box.push_back(k);
                    }

                    res.push_back(box);
                    box.clear();
                } else if (mysum > sum) {
                    break;
                }
            }
        }

        return res;
    }
};
