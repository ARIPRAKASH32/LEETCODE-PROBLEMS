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
class CBTInserter {
    vector<TreeNode*>curr;
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*>q;
        if(root){
            q.push(root);
            curr.push_back(root);
        }

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                curr.push_back(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
                curr.push_back(temp->right);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        int parIdx = curr.size() == 1 ? 0 : (curr.size() - 2) / 2;
        TreeNode* par = curr[parIdx];
        curr.push_back(newNode);

        if(par->left == NULL){
            par->left = newNode;
        }else if(par->right == NULL){
            par->right = newNode;
        }else{
            TreeNode* par_plus = curr[parIdx+1];
            par_plus->left = newNode;
            return par_plus->val;
        }
        return par->val;
    }
    
    TreeNode* get_root() {
        if(curr.size() == 0) return NULL;
        return curr[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
