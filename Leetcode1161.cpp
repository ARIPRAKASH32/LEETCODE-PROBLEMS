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
    static int maxLevelSum(TreeNode* root) {
        int idx=0, sum=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        for( ; !q.empty(); level++){
            int qz=q.size();
            int curSum=0;
            for (int i=0; i<qz; i++) {
                TreeNode* Node=q.front(); q.pop();
                curSum+=Node->val;
                if (Node->left) q.push(Node->left);
                if (Node->right) q.push(Node->right);
            }
            if(curSum>sum) idx=level, sum=curSum;
        } 
        return idx;
    }
};
