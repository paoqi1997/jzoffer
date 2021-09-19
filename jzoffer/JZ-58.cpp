/**
 * 58. 对称的二叉树
 * https://www.nowcoder.com/questionTerminal/ff05d44dfdb04e1d83bdbdab320efbcb
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetrical(TreeNode *pRoot) {
        return isSame(pRoot, pRoot);
    }

    bool isSame(TreeNode *pRoot1, TreeNode *pRoot2) {
        // 两个均为nullptr
        if (pRoot1 == nullptr && pRoot2 == nullptr) {
            return true;
        }
        // 其中一个为nullptr
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }

        bool resL = isSame(pRoot1->left, pRoot2->right);
        bool resR = isSame(pRoot1->right, pRoot2->left);

        return pRoot1->val == pRoot2->val && resL && resR;
    }
};
