/**
 * 3. 从尾到头打印链表
 * https://www.nowcoder.com/questionTerminal/d0267f7f55b3412ba93bd35cfa8e8035
 */

#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        ListNode *p = head;
        vector<int> res;

        while (p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> printListFromTailToHead_v2(ListNode *head) {
        vector<int> res;

        if (head != nullptr) {
            __printListFromTailToHead_v2(res, head);
        }

        return res;
    }

    void __printListFromTailToHead_v2(vector<int>& res, ListNode *p) {
        if (p->next != nullptr) {
            __printListFromTailToHead_v2(res, p->next);
        }

        res.push_back(p->val);
    }
};
