/**
 * 56. 删除链表中重复的结点
 * https://www.nowcoder.com/questionTerminal/fc533c45b73a41b0b44ccba763f866ef
 */

#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode *pHead) {
        if (pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }

        unique_ptr<ListNode> preHead(new ListNode(-1));
        preHead->next = pHead;

        ListNode *prev = preHead.get(), *curr = preHead->next;

        // -1(preHead) ---> 1(pHead) ---> 2 ---> 3 ---> 3 ---> 4 ---> 5

        while (curr != nullptr) {
            if (curr->next != nullptr && curr->next->val == curr->val) {
                while (curr->next != nullptr && curr->next->val == curr->val) {
                    curr = curr->next;
                }

                curr = curr->next;
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return preHead->next;
    }
};
