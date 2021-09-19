/**
 * 62. 二叉搜索树的第k个结点
 * https://www.nowcoder.com/questionTerminal/ef068f602dde4d28aab2b210e859150a
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* KthNode(TreeNode *pRoot, int k) {
        TreeNode *res = nullptr;

        int idx = 0;
        kthNode(pRoot, k, res, idx);

        return res;
    }

    void kthNode(TreeNode *pRoot, int k, TreeNode*& res, int& idx) {
        if (pRoot != nullptr) {
            kthNode(pRoot->left, k, res, idx);

            if (++idx == k) {
                res = pRoot;
            }

            kthNode(pRoot->right, k, res, idx);
        }
    }
};
