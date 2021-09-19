/**
 * 26. 二叉搜索树与双向链表
 * https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* Convert(TreeNode *pRootOfTree) {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }

        TreeNode *prev = nullptr;
        __convert(prev, pRootOfTree);
        TreeNode *ph = pRootOfTree;

        // 头节点在最左边
        while (ph->left != nullptr) {
            ph = ph->left;
        }

        return ph;
    }

    /**
     * 要求返回的是有序的双向链表，所以借用了中序遍历的思想。
     */
    void __convert(TreeNode*& prev, TreeNode *curr) {
        if (curr != nullptr) {
            // 类似于__inorder(node->left)
            __convert(prev, curr->left);

            if (prev != nullptr) {
                prev->right = curr;
            }

            curr->left = prev;
            prev = curr;

            // 类似于__inorder(node->right)
            __convert(prev, curr->right);
        }
    }
};
