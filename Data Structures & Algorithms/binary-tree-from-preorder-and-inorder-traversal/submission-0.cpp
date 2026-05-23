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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(preorder[0]);
        int left_size, right_size;
        for (int i = 0; i < n; i++) {
            if (inorder[i] == preorder[0]) {
                left_size = i;
                right_size = n-i-1;
                break;
            }
        }
        vector<int> preorder_left(preorder.begin()+1, preorder.begin()+1+left_size);
        vector<int> inorder_left(inorder.begin(), inorder.begin()+left_size);
        vector<int> preorder_right(preorder.begin()+1+left_size, preorder.end());
        vector<int> inorder_right(inorder.begin()+left_size+1, inorder.end());
        
        node->left = buildTree(preorder_left, inorder_left);
        node->right = buildTree(preorder_right, inorder_right);
        return node;
    }
};