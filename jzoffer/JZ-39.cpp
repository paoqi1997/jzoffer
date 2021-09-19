/**
 * 39. 平衡二叉树
 * https://www.nowcoder.com/questionTerminal/8b3b95850edb4115918ecebdf1b4d222
 */

#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode *pRoot) {
        map<TreeNode*, int> d;

        depth(d, pRoot);

        return judge(d, pRoot);
    }

    int depth(map<TreeNode*, int>& d, TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        if (d.find(node) != d.end()) {
            return d[node];
        }

        int ld = depth(d, node->left);
        int rd = depth(d, node->right);

        d[node] = max(ld, rd) + 1;
        return d[node];
    }

    bool judge(map<TreeNode*, int>& d, TreeNode *node) {
        if (node == nullptr) {
            return true;
        }

        bool res = abs(d[node->left] - d[node->right]) <= 1;
        return res && judge(d, node->left) && judge(d, node->right);
    }
};
