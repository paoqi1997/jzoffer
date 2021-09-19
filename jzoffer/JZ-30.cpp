/**
 * 30. 连续子数组的最大和
 * https://www.nowcoder.com/questionTerminal/459bd355da1549fa8a49e350bf3df484
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int currCrest = array[0], crest = array[0];

        for (size_t i = 1; i < array.size(); ++i) {
            currCrest = max(currCrest + array[i], array[i]);
            crest = max(currCrest, crest);
        }

        return crest;
    }
};
