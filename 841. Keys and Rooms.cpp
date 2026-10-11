class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        queue<int> q;
        for (int x : rooms[0]) {
            q.push(x);
            vis[x] = true;
        }
        vis[0] = true;
        while(!q.empty()) {
            int room = q.front();
            q.pop();
            for (int x : rooms[room]) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        for (bool x : vis) {
            if(x == false) return false;
        }
        return true;
    }
};
