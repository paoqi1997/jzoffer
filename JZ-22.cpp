/**
 * 22. 从上往下打印二叉树
 * https://www.nowcoder.com/questionTerminal/7fe2212963db4790b57431d9ed259701
 */

#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> vals;
        queue<TreeNode*> nodes;

        while (root != nullptr) {
            vals.push_back(root->val);
            if (root->left != nullptr) {
                nodes.push(root->left);
            }
            if (root->right != nullptr) {
                nodes.push(root->right);
            }

            if (nodes.empty()) {
                break;
            } else {
                root = nodes.front();
                nodes.pop();
            }
        }

        return vals;
    }
};
