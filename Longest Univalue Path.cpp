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
    //val,cnt
    int maxPath = 0;
    pair<int,int> dfs(TreeNode* root){
        if(root->left == NULL && root->right==NULL){
            return {root->val,1};
        }
        pair<int,int>leftData = {-1001,0};
        pair<int,int>rightData = {-1001,0};
        if(root->left != NULL){
            leftData = dfs(root->left);
        }
        if(root->right != NULL){
            rightData = dfs(root->right);
        }
        int leftMaxVal = leftData.second;
        int rightMaxVal = rightData.second;
        int leftVal = leftData.first;
        int rightVal = rightData.first;
        if(leftVal == rightVal && rightVal == root->val){
            maxPath = max(maxPath,1+leftMaxVal+rightMaxVal);
        }
        int localMaxiPath = 1;
        if(root->val == leftVal){
            localMaxiPath = max(localMaxiPath,leftMaxVal+1);
        }
        if(root->val == rightVal){
            localMaxiPath = max(localMaxiPath,rightMaxVal+1);
        }
        maxPath = max(maxPath,localMaxiPath);
        return {root->val,localMaxiPath};
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root);
        return max(0,maxPath-1);
    }
};
