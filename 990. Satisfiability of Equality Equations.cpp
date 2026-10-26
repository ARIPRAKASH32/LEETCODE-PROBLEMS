class DSU{
    private:
        vector<int> parent;
        vector<int> size;

    public:
        DSU(int n)
        {
            parent.resize(n);
            size.resize(n,1);
            
            for(int i=0; i<n; i++)
            {
                parent[i]=i;
            }
        }

        int find(int x)
        {
            if(parent[x]==x) return x;

            return parent[x]=find(parent[x]);
        }

        bool Union(int a, int b)
        {
            int rootA = find(a);
            int rootB = find(b);

            if(rootA == rootB) return true;

            if(size[rootA]<size[rootB])
            {
                swap(rootA,rootB);
            }

            parent[rootB]=rootA;
            size[rootA]+=size[rootB];

            return false;
        }

        
        void printComponents()
        {
            unordered_map<int,vector<int>> components;

            for(int i=0; i<parent.size(); i++)
            {
                components[find(i)].push_back(i);
            }

            cout<<"\nConnected Components\n";

            for(auto &it : components)
            {
                cout<<"Root "<<it.first<<" : ";

                for(int node: it.second)
                {
                    cout<<node<<" ";
                }
                cout<<endl;
            }
        }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        unordered_map<char, int> mp;
        int k = 0;

        for (const string &str : equations)
        {
            if (mp.find(str[0]) == mp.end())
                mp[str[0]] = k++;

            if (mp.find(str[3]) == mp.end())
                mp[str[3]] = k++;
        }

        DSU dsu(k);

        for (const string &str : equations)
        {
            if (str[1] == str[2])
            {
                dsu.Union(mp[str[0]], mp[str[3]]);
            }
        }

        dsu.printComponents();

        for (const string &str : equations)
        {
            if (str[1] != str[2])
            {
                if (dsu.find(mp[str[0]]) == dsu.find(mp[str[3]]))
                {
                    return false;
                }
            }
        }

        return true;
    }
};
