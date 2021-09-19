/**
 * 15. 反转链表
 * https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode *pHead) {
        ListNode *p = pHead, *node = nullptr;

        while (p != nullptr) {
            ListNode *q = p->next;
            p->next = node;
            node = p;
            p = q;
        }

        return node;
    }
};
