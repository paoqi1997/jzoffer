/**
 * 60. 把二叉树打印成多行
 * https://www.nowcoder.com/questionTerminal/445c44d982d04483b04a54f298796288
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
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> res;

        if (pRoot == nullptr) {
            return res;
        }

        queue<TreeNode*> nodes;

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

            res.emplace_back(tmp);
        }

        return res;
    }
};
