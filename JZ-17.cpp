/**
 * 17. 树的子结构
 * https://www.nowcoder.com/questionTerminal/6e196c44c7004d15b1610b9afca8bd88
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool HasSubtree(TreeNode *pRootA, TreeNode *pRootB) {
        bool r = false;

        if (pRootA != nullptr && pRootB != nullptr) {
            r = isBinA(pRootA, pRootB);
            if (!r) {
                r = HasSubtree(pRootA->left, pRootB);
            }
            if (!r) {
                r = HasSubtree(pRootA->right, pRootB);
            }
        }

        return r;
    }

    bool isBinA(TreeNode *pRootA, TreeNode *pRootB) {
        if (pRootB == nullptr) {
            return true;
        }
        if (pRootA == nullptr) {
            return false;
        }

        if (pRootA->val == pRootB->val) {
            return isBinA(pRootA->left, pRootB->left) && isBinA(pRootA->right, pRootB->right);
        } else {
            return false;
        }
    }
};
