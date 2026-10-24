class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        auto& vec = mp[key];
        int left = 0, right = vec.size() - 1;
        string res = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
