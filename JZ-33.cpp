/**
 * 33. 丑数
 * https://www.nowcoder.com/questionTerminal/6aa9e04fc3794f68acf8778237ba065b
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7) {
            return index;
        }

        vector<int> box(index + 1);
        box[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i <= index; ++i) {
            // 获取丑数
            box[i] = min(box[i2] * 2, min(box[i3] * 3, box[i5] * 5));

            // 该丑数通过乘以2得到，接下来将目标转向下一个乘以2得到的丑数
            if (box[i] == box[i2] * 2) ++i2;
            // 该丑数通过乘以3得到，接下来将目标转向下一个乘以3得到的丑数
            if (box[i] == box[i3] * 3) ++i3;
            // 该丑数通过乘以5得到，接下来将目标转向下一个乘以5得到的丑数
            if (box[i] == box[i5] * 5) ++i5;
        }

        return box[index - 1];
    }
};
