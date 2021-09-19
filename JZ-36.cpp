/**
 * 36. 两个链表的第一个公共结点
 * https://www.nowcoder.com/questionTerminal/6ab1d9a29e88450685099d45c9e31e46
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return nullptr;
        }

        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);

        // 1-3-5
        //      \
        //       7-9-11
        //      /
        //   4-6
        if (len1 < len2) {
            int gap = len2 - len1;
            while (gap-- > 0) {
                pHead2 = pHead2->next;
            }
        } else {
            int gap = len1 - len2;
            while (gap-- > 0) {
                pHead1 = pHead1->next;
            }
        }

        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1 == pHead2) {
                return pHead1;
            }

            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }

        return nullptr;
    }

    int getLength(ListNode *pHead) {
        int length = 0;

        auto p = pHead;
        while (p != nullptr) {
            p = p->next;
            ++length;
        }

        return length;
    }
};
