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

    tuple<int, int, int> processTree(TreeNode *root) {
        if (root == nullptr) {
            return {-1, 0, 0};
        }
        auto [isValid1, smallest1, largest1] = processTree(root->left);
        if (isValid1 == 0 || (isValid1 == 1 && largest1 >= root->val)) {
            return {0, 0, 0};
        }
        auto [isValid2, smallest2, largest2] = processTree(root->right);
        if (isValid2 == 0 || (isValid2 == 1 && smallest2 <= root->val)) {
            return {0, 0, 0};
        }
        int smallest = isValid1 != -1 ? smallest1 : root->val;
        int largest = isValid2 != -1 ? largest2 : root->val;

        return {1, smallest, largest};
    }

public:
    bool isValidBST(TreeNode* root) {
        auto [answer, _, _] = processTree(root);
        return answer != 0;
    }
};