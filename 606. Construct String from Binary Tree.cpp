class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) {
            return "";
        }

        string result;
        dfs(root, result);

        return result;        
    }

private:
    void dfs(TreeNode* node, string& result) {
        if (!node) {
            return;
        }

        result += to_string(node->val);

        if (node->left || node->right) {
            result += "(";
            dfs(node->left, result);
            result += ")";

            if (node->right) {
                result += "(";
                dfs(node->right, result);
                result += ")";
            }
        }
    }
};
