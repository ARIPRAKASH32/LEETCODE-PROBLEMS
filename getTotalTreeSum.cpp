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
static int MOD=1e9+7;
class Solution {
public:
    long long totalTreeSum=0,result=0;
    void getTotalTreeSum(TreeNode* root)   
    {
        if(!root)
            return;
        totalTreeSum+=root->val;
        getTotalTreeSum(root->left);
        getTotalTreeSum(root->right);
    }
    int SumUnder(TreeNode* root)           
    {
       if(!root)
            return 0;
       int sumUnderLeft=SumUnder(root->left),sumUnderRight=SumUnder(root->right); 
       result=max({result,(totalTreeSum-sumUnderLeft)*sumUnderLeft,(totalTreeSum-sumUnderRight)*sumUnderRight});
       return sumUnderLeft+sumUnderRight+root->val;
    }
    int maxProduct(TreeNode* root) 
    {
        getTotalTreeSum(root);
        SumUnder(root);
        return result%MOD;
    }
};
