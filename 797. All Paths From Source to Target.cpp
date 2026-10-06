class Solution {
void dfs(vector<vector<int>>& graph,int source,int dest,vector<vector<int>>&res,vector<int>path){
    path.push_back(source);
    if(source==dest){
        res.push_back(path);
        return;
    }

    for(int &v:graph[source]){
        dfs(graph,v,dest,res,path);
    }
    path.pop_back();
    return;
}
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>res;
        vector<int>path;

        dfs(graph,0,n-1,res,path);
        return res;
    }
};
