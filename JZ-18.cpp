/**
 * 18. 二叉树的镜像
 * https://www.nowcoder.com/questionTerminal/a9d0ecbacef9410ca97463e4a5c83be7
 */

#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* Mirror(TreeNode *pRoot) {
        __mirror(pRoot);
        return pRoot;
    }

    void __mirror(TreeNode *pRoot) {
        if (pRoot) {
            swap(pRoot->left, pRoot->right);
            __mirror(pRoot->left);
            __mirror(pRoot->right);
        }
    }
};
