class Solution {
public:
    int help(TreeNode*root, int &val){
        if(!root) return 0;
        help(root->right, val); 
        root->val += val; 
        val = root->val;
        help(root->left, val);
        return val;
    }
    TreeNode* bstToGst(TreeNode* root) {
		int total = 0;
        help(root, total);
        return root; 
    }
};
