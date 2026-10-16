class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string>st;
        for(auto &w:words){
            string odd;
            string even;
            for(int i=0; i<w.size(); ++i){
                if(i%2) odd.push_back(w[i]);
                else even.push_back(w[i]);
            }
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
            st.insert(odd+even);
        }
        return st.size();
    }
};
