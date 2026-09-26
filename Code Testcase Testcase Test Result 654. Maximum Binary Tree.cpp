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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {// TC : O(N)+O(N)+O(N)+O(N)+O(N) = O(N) & SC : O(N)

        stack<TreeNode*>st;//SC : O(N)

        for(auto x : nums){//O(N)

            TreeNode* curr = new TreeNode(x);

            while(!st.empty() && st.top()->val < x){// Overall time complexity for while is O(N) , Since every element Is pushed once into the stack and popped out once.
                curr->left = st.top();
                st.pop();
            }

            if(!st.empty()){
                st.top()->right = curr;
            }

            st.push(curr);// TC : O(N)
        }

        // Total time complexity for adding left and right for every node is O(N)

        while(st.size() > 1){//O(N)
            //At all times, the stack is monotonically decreasing from bottom to top,So the largest element currently in the stack is always at the bottom.
            st.pop();
        }

        return st.top();
    }
};
