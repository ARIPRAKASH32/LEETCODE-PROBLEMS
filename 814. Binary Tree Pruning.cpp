class Solution {
public:

    bool solve(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }

        bool left = solve(root->left);
        bool right = solve(root->right);

        if (!left) {
            root->left = nullptr;
        }

        if (!right) {
            root->right = nullptr;
        }

        return root->val == 1 || left || right;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (!solve(root)) {
            return nullptr;
        }

        return root;
    }
};
