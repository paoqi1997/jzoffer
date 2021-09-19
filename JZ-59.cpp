/**
 * 59. 按之字形顺序打印二叉树
 * https://www.nowcoder.com/questionTerminal/91b69814117f4e8097390d107d2efbe0
 */

#include <algorithm>
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
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> res;

        if (pRoot == nullptr) {
            return res;
        }

        queue<TreeNode*> nodes;
        size_t level = 0;

        nodes.push(pRoot);

        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> tmp;

            while (size-- > 0) {
                auto node = nodes.front();
                nodes.pop();

                tmp.emplace_back(node->val);

                if (node->left != nullptr) {
                    nodes.push(node->left);
                }
                if (node->right != nullptr) {
                    nodes.push(node->right);
                }
            }

            if (++level % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }

            res.emplace_back(tmp);
        }

        return res;
    }
};
