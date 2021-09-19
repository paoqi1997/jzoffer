/**
 * 24. 二叉树中和为某一值的路径
 * https://www.nowcoder.com/questionTerminal/b736e784e3e34731af99065031301bca
 */

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
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        vector<vector<int>> paths;
        vector<int> path;

        if (root) {
            dfs(root, expectNumber, paths, path);
        }

        return paths;
    }

    void dfs(TreeNode *root, int expectNumber, vector<vector<int>>& paths, vector<int>& path) {
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == expectNumber) {
                paths.push_back(path);
            }
        }

        if (root->left != nullptr) {
            dfs(root->left, expectNumber - root->val, paths, path);
        }
        if (root->right != nullptr) {
            dfs(root->right, expectNumber - root->val, paths, path);
        }

        path.pop_back();
    }
};
