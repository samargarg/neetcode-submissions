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

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int myD = maxDepth(root->left) + maxDepth(root->right);
        int maxLeft = diameterOfBinaryTree(root->left);
        int maxRight = diameterOfBinaryTree(root->right);
        int ans = max(myD, maxLeft);
        ans = max(ans, maxRight);
        return ans;
    }
};