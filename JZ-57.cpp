/**
 * 57. 二叉树的下一个结点
 * https://www.nowcoder.com/questionTerminal/9023a0c988684a53960365b889ceaf5e
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode *pNode) {
        if (pNode == nullptr) {
            return nullptr;
        }

        if (pNode->right != nullptr) {
            pNode = pNode->right;

            while (pNode->left != nullptr) {
                pNode = pNode->left;
            }

            return pNode;
        }

        while (pNode->next != nullptr) {
            auto root = pNode->next;

            if (root->left == pNode) {
                return root;
            }

            pNode = pNode->next;
        }

        return nullptr;
    }
};
