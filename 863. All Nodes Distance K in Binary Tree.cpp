/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> adj=vector<vector<int>> (501);
    vector<int> ans;
    vector<int> vis=vector<int> (501,0);
    
    void bfs(TreeNode* target,int  k){
        for(int i=0;i<501;i++){
            vis[i]=0;
        }   
        queue<int> q;
        int dist=0;
        q.push(target->val);
        vis[target->val]=1;
        while(!q.empty()){
            int n=q.size();
            if(dist==k){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }return;
            }else{
                while(n--){
                    int node=q.front();
                    q.pop();
                    vis[node]=1;
                    for(int i:adj[node]){
                        if(!vis[i]){
                            vis[i]=1;
                            q.push(i);
                        }
                    }
                }
            }
            dist++;

            
        }
    }
    void build(TreeNode* root){
        if(!root) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            build(root->left);
        }
        if(root->right){
             adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            build(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        bfs(target,k);
        
        return ans;
    }
};
