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

    int answer;

    int getMaxPath(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int left = getMaxPath(node->left);
        int right = getMaxPath(node->right);
        int this_ans = node->val;
        if (left > 0) {
            this_ans += left;
        }
        if (right > 0) {
            this_ans += right;
        }
        answer = max(answer, this_ans);
        int return_value = node->val;
        int maxi = max(left, right);
        if (maxi > 0) {
            return_value += maxi; 
        }
        return return_value;
    }

public:
    int maxPathSum(TreeNode* root) {
        answer = -1000;
        getMaxPath(root);
        return answer;
    }
};