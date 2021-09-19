/**
 * 48. 不用加减乘除做加法
 * https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
 */

class Solution {
public:
    int Add(int num1, int num2) {
        int result, carry;

        do {
            result = num1 ^ num2;       // 没有处理进位的加法
            carry = (num1 & num2) << 1; // 进位
            num1 = result;
            num2 = carry;
        } while (carry != 0); // 进位不为0就继续进行

        return result;
    }
};
