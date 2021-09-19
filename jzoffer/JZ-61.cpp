/**
 * 61. 序列化二叉树
 * https://www.nowcoder.com/questionTerminal/cf7e25aa97c04cc1a68c8f040e71fb84
 */

#include <cstring>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 按前序遍历的方式将二叉树序列化为字符串
     */
    char* Serialize(TreeNode *root) {
        if (root == nullptr) {
            return "#";
        }

        string s = to_string(root->val);
        s.push_back(',');

        char *left = Serialize(root->left);
        char *right = Serialize(root->right);

        char *res = new char[s.length() + strlen(left) + strlen(right)];

        strcpy(res, s.c_str());
        strcat(res, left);
        strcat(res, right);

        return res;
    }

    /**
     * 按前序遍历的方式将字符串反序列化为二叉树
     */
    TreeNode* Deserialize(char *str) {
        return deserialize(str);
    }

    TreeNode* deserialize(char*& s) {
        if (*s == '#') {
            ++s;
            return nullptr;
        }

        int num = 0;

        while (*s != ',') {
            num = num * 10 + (*s - '0');
            ++s;
        }

        ++s;

        auto root = new TreeNode(num);

        root->left = deserialize(s);
        root->right = deserialize(s);

        return root;
    }
};
