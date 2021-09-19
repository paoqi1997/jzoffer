/**
 * 16. 合并两个排序的链表
 * https://www.nowcoder.com/questionTerminal/d8b6b4358f774294a89de2a6ac4d9337
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* Merge(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == nullptr) {
            return pHead2;
        }
        if (pHead2 == nullptr) {
            return pHead1;
        }

        if (pHead1->val <= pHead2->val) {
            // pHead1 -> (pHead1->next) -> ...
            // pHead2 -> ...
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        } else {
            // pHead1 -> ...
            // pHead2 -> (pHead2->next) -> ...
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};
