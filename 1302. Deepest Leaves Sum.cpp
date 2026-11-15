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
    int h;
    int hei(TreeNode*root){
        if(root==NULL)return 0;
        return max(1+hei(root->left),1+hei(root->right));
    }
    int sum(TreeNode* root, int i){
        if(root==NULL)return 0;
        if(i==h){
            return root->val;
        }
        return sum(root->left,i+1) + sum(root->right,i+1);
    }
  
    int deepestLeavesSum(TreeNode* root) {
        h=hei(root);
        if(root==NULL)return 0;
        return sum(root,1);
    }
};
