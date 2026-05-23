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

    int getGoodCount(TreeNode *root, int maxi) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        if (root->val >= maxi) {
            count++;
        }
        int new_max = max(maxi, root->val);
        count += getGoodCount(root->left, new_max);
        count += getGoodCount(root->right, new_max);
        return count;
    }

public:
    int goodNodes(TreeNode* root) {
        return getGoodCount(root, -1e4);
    }
};