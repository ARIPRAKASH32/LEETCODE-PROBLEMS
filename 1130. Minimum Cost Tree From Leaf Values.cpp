class Solution {
public:
    int n;
    int mctFromLeafValues(vector<int>& arr) {
        this->n=arr.size();
       stack<int>st;
       st.push(INT_MAX);
       int ans=0;
       for(auto it:arr){
         while(!st.empty() && it>st.top()){
            int node=st.top();
            st.pop();
            ans+=node*min(it,st.top());
         }
         st.push(it);
       }
       int node=st.top();
       st.pop();
       while(st.size()>1){
        int currNode=st.top();
        ans+=node*currNode;
        node=currNode;
        st.pop();
       }
       return ans;
    }
};
