#define ll long long
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> a;
        stringstream ss(preorder);
        string token;
        while (getline(ss, token, ',')) {
            a.push_back(token);
        }
        ll vis = 0, n = a.size();
        for (ll i = 0; i < n; i++) {
            if (vis < i) return false;
            if (a[i] == "#") continue;
            vis += 2;
        }
        if (vis != n - 1) return false;
        return true;
    }
};
