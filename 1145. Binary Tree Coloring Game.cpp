class Solution {
public:
    TreeNode* X;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector <int> child(n+1,0);
        
        dfs(root,0,x,child);
        
        if(child[root->val]>2*child[x]) return true;
        if(X->left and 2*child[X->left->val]>child[root->val]) return true;
        if(X->right and 2*child[X->right->val]>child[root->val]) return true;
        return false;
    }
protected:
    int dfs(TreeNode* root, int parent, int x, vector<int>&child){
        if(!root) return 0;
        
        int left = dfs(root->left,root->val,x,child);
        int right = dfs(root->right,root->val,x,child);
        
        return child[root->val] = 1+left+right;
    }
};
