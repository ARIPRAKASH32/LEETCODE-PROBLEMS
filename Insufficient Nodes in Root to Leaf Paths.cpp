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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return helper(root, limit, 0);
    }

    TreeNode* helper(TreeNode* root, int limit, int sum = 0){
        if(!root) return NULL;

        if(!root -> left && !root -> right){
            return root -> val + sum < limit ? NULL : root;
        }

        root->left = helper(root->left, limit, sum + root->val);
        root->right = helper(root->right, limit, sum + root->val);

        return (!root->left && !root->right) ? NULL : root;
    }
};
