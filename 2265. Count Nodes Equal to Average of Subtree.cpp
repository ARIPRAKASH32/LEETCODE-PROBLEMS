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
    using int2=pair<int, int>;
public:
    int count=0;
    int2 postOrder(TreeNode* node){
        if (node==NULL) return {0, 0};
        auto [sumL, iL]=postOrder(node->left);
        auto [sumR, iR]=postOrder(node->right);
        int sum=node->val, i=1;
        sum+=(sumL+sumR);
        i+=(iL+iR);
        if (sum/i==node->val) count++;
    //    cout<<node->val<<" n="<<i<<" sum="<<sum<<endl;
        return {sum, i};
    }

    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return count;
    }
};
