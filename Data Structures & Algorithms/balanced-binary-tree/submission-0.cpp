/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    int getDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if (left == -1 || right == -1) {
            return -1;
        }
        if (abs(left-right) > 1) {
            return -1;
        }
        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
};