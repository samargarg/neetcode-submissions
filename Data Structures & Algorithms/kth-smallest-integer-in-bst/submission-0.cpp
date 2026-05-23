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

    int count(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + count(root->left) + count(root->right);
    }


public:
    int kthSmallest(TreeNode* root, int k) {
        int left = count(root->left);
        if (left >= k) {
            return kthSmallest(root->left, k);
        } else if (left + 1 == k) {
            return root->val;
        } else {
            return kthSmallest(root->right, k-left-1);
        }
    }
};