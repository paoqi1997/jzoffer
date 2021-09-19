/**
 * 55. 链表中环的入口结点
 * https://www.nowcoder.com/questionTerminal/253d2c59ec3e4bc68da16833f79a38e4
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode *pHead) {
        if (pHead == nullptr || pHead->next == nullptr) {
            return nullptr;
        }

        ListNode *pFast = pHead, *pSlow = pHead;

        // 1 -> 2 -> 3 -> 4
        //           ^    |
        //           |    v
        //           6 <- 5

        while (pFast != nullptr && pFast->next != nullptr) {
            pFast = pFast->next->next; // 二倍速
            pSlow = pSlow->next;       // 一倍速

            // 也可以先计算环的长度（即环的节点数目），
            // 对于有环链表来说，其长度即为非环部分 + 环的长度，
            // 让 pSlow 从头节点出发，先走一个环的长度，
            // 然后与同样从头节点出发的 slow 一起走非环部分的长度，最后两者在环的入口节点相遇。
            if (pFast == pSlow) {
                ListNode *slow = pHead;

                while (slow != pSlow) {
                    slow = slow->next;
                    pSlow = pSlow->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};
