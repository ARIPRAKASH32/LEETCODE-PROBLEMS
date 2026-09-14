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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) return -1;

        std::queue<TreeNode*> q;
        q.push(root);
        int minVal = root->val, secondMin = INT_MAX;
        bool found = false;
        
        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode->left != NULL) {
                q.push(currNode->left);
                q.push(currNode->right);

                if(currNode->left->val != minVal) {
                    secondMin = min(secondMin, currNode->left->val);
                    found = true;
                }
                if(currNode->right->val != minVal) {
                    secondMin = min(secondMin, currNode->right->val);
                    found = true;
                }
            }
        }
        return found ? secondMin : -1;
    }
};
