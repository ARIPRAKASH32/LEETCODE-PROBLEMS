class Solution {
public:
    struct DSU{
        vector<int> parent,sz;
        int components;

        DSU(int n): parent(n),sz(n,1),components(n){
            iota(parent.begin(),parent.end(),0);
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        bool unite(int a,int b){
            a=find(a);
            b=find(b);
            if(a==b) return false;
            if(sz[a]<sz[b]) swap(a,b);
            parent[b]=a;
            sz[a]+=sz[b];
            components--;
            return true;
        }

        bool isconnected(int a,int b){
            return find(a)==find(b);
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size(),incr=0;
        int total = 0;
        for(auto &account : accounts)
            total += account.size();

        DSU dsu(total);
        unordered_map<string,int> emailtoid;
        unordered_map<int,string> idtoname;

        for(int i=0;i<n;i++){
            int namid=incr++;
            idtoname[namid]=accounts[i][0];
            for(int j=1;j<accounts[i].size();j++){
                if(emailtoid.count(accounts[i][j])==0){
                    emailtoid[accounts[i][j]]=incr;
                    idtoname[incr]=accounts[i][j];
                    incr++;
                }
                dsu.unite(namid,emailtoid[accounts[i][j]]);
            }
        }

        vector<vector<string>> sol(total);
        for (auto &[email, id] : emailtoid) {
            int root = dsu.find(id);
            sol[root].push_back(email);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < incr; i++) {
            if(sol[i].empty()) continue;
            vector<string> curr;
            curr.push_back(idtoname[i]);
            sort(sol[i].begin(),sol[i].end());
            for(auto &email : sol[i])
                curr.push_back(email);
            ans.push_back(curr);
        }
        return ans;
    }
};
