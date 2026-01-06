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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int ans = -1, maxSum = INT_MIN, level= 0;
        while(!q.empty()){
            level++;    //increase one level every time
            int size = q.size(), sum = 0;

            while(size--){
                auto node = q.front();
                q.pop();

                //sum the level's node
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum> maxSum){
                maxSum = sum;
                ans = level;
            }
        }

        return ans;
    }
};
