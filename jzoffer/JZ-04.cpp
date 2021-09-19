/**
 * 4. 重建二叉树
 * https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6
 */

#include <vector>

using namespace std;

/**
 * Definition for binary tree.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        if (pre.empty()) {
            return nullptr;
        }

        // pre: 根左右 [1, 2, 3, 4, 5, 6, 7]
        // in:  左根右 [3, 2, 4, 1, 6, 5, 7]
        TreeNode *root = new TreeNode(pre[0]);

        size_t rootindex = 0, size = in.size();

        for (size_t i = 0; i < size; ++i) {
            // 查找当前根节点
            if (in[i] == pre[0]) {
                rootindex = i;
                break;
            }
        }

        vector<int> lpre, lin, rpre, rin;

        // 构建左子树
        for (size_t i = 0; i < rootindex; ++i) {
            lpre.push_back(pre[i + 1]); // 从1开始，回避pre[0]
            lin.push_back(in[i]);
        }

        // 构建右子树
        for (size_t i = rootindex + 1; i < size; ++i) {
            rpre.push_back(pre[i]);
            rin.push_back(in[i]);
        }

        // 递归构建左右子节点
        root->left = reConstructBinaryTree(lpre, lin);
        root->right = reConstructBinaryTree(rpre, rin);

        return root;
    }
};
