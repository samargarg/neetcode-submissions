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
        addToMap(root->left, ctr+1);
        addToMap(root->right, ctr+1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        addToMap(root, 0);
        vector<vector<int>> answer;

        for (auto [key, value]: ans) {
            answer.push_back(value);
        }   
        return answer;
    }
};