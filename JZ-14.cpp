/**
 * 14. 链表中倒数第k个结点
 * https://www.nowcoder.com/questionTerminal/886370fe658f41b498d40fb34ae76ff9
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (pHead == nullptr || k == 0) {
            return nullptr;
        }

        // 快慢指针
        ListNode *p = pHead, *q = pHead;

        // 1 -> 2 -> 3 -> 4 -> nullptr
        for (int i = 0; i < k; ++i) {
            if (p != nullptr) {
                p = p->next;
            } else {
                return nullptr;
            }
        }

        // 找到倒数第3个节点需要从头节点右移1次
        while (p != nullptr) {
            p = p->next;
            q = q->next;
        }

        return q;
    }
};
