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
    
    vector<int> getAnswer(TreeNode* root, vector<int> voyage)
    {
        vector<int> ans;
        int ind = 0;
        stack<TreeNode*> st;

        st.push(root);
        while(!st.empty() && ind<voyage.size())
        {
            if(st.top()->val==voyage[ind])
            {
                ind++;
                TreeNode* temp = st.top();
                st.pop();

                if(temp->left && temp->left->val==voyage[ind])
                {
                    if(temp->right)
                    {
                        st.push(temp->right);
                    }
                    st.push(temp->left);
                }
                else if(temp->right && temp->right->val==voyage[ind])
                {
                    if(temp->left)
                    {
                        ans.push_back(temp->val);
                        st.push(temp->left);
                    }
                    st.push(temp->right);
                }
                else if(temp->left || temp->right)
                {
                    return {-1};
                }
            }
            else
            {
                return {-1};
            }
        }
        return ans;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> v = getAnswer(root, voyage);

        
        return v;
    }
};
