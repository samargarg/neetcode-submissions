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

    map<int, vector<int>> ans;

    void addToMap(TreeNode *root, int ctr) {
        if (root == nullptr) {
            return;
        }
        ans[ctr].push_back(root->val);
        addToMap(root->right, ctr+1);
        addToMap(root->left, ctr+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        addToMap(root, 0);
        vector<int> answer;

        for (auto [key, value]: ans) {
            answer.push_back(value[0]);
        }
        return answer;
    }
};