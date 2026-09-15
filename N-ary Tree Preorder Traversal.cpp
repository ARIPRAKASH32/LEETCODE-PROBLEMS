/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void pre_order(Node* root , vector<int>& pre){
        if(root == nullptr)
        return ;

        pre.push_back(root->val);
        for(auto x : root->children){
            pre_order(x,pre);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> pre;
        pre_order(root,pre);
        return pre;
    }
};
