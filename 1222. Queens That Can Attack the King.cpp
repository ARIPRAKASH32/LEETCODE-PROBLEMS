class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        vector<vector<int>>ans;

        set<pair<int,int>>st;

        for(auto& i : queens){
            st.insert({i[0],i[1]});
        }

        int dr[] = {-1,-1,0,1,1,1,0,-1};
        int dc[] = {0,1,1,1,0,-1,-1,-1};

        for(int d=0;d<8;d++){
            
            int ni = king[0];
            int nj = king[1];

            vector<int>queen;

            while(true){
               
               ni = ni+dr[d];
               nj = nj+dc[d];

               if(ni<0 || ni>=8 || nj<0 || nj>=8) break;

               else if(st.find({ni,nj}) != st.end()){
                    queen.push_back(ni);
                    queen.push_back(nj);
                    break;
               }

            }

            if(queen.size() > 0) ans.push_back(queen);
        }
        return ans;
    }
};
