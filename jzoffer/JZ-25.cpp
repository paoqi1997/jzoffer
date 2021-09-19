/**
 * 25. 复杂链表的复制
 * https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba
 */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode *pHead) {
        if (pHead == nullptr) {
            return pHead;
        }

        auto p = pHead;

        while (p != nullptr) {
            // 复制节点并将新的节点连接到原来的节点的后面
            // p -> q
            // p -> cloneNode -> q
            auto q = p->next;
            auto cloneNode = new RandomListNode(p->label);
            p->next = cloneNode;
            cloneNode->next = q;
            p = q;
        }

        p = pHead;

        while (p != nullptr) {
            // 为新的节点设置random
            // p ---> p->next ---> p->next->next
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        p = pHead;
        auto ph = pHead->next;

        while (p != nullptr) {
            // 拆分链表
            // p ---> p->next(cloneNode) ---> cloneNode->next
            auto cloneNode = p->next;
            p->next = cloneNode->next;

            if (cloneNode->next != nullptr) {
                cloneNode->next = cloneNode->next->next;
            }

            p = p->next;
        }

        return ph;
    }
};
