/**
 * 38. 二叉树的深度
 * https://www.nowcoder.com/questionTerminal/435fb86331474282a3499955f0a41e8b
 */

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int TreeDepth(TreeNode *pRoot) {
        if (pRoot == nullptr) {
            return 0;
        }

        int lh = TreeDepth(pRoot->left);
        int rh = TreeDepth(pRoot->right);

        return max(lh, rh) + 1;
    }
};
