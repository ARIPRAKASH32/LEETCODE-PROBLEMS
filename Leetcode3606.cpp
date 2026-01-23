class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string , int> busi = {
            
            {"electronics" , 0},
            {"grocery" , 1},
            {"pharmacy" , 2},
            {"restaurant", 3}
            
        };

        vector<pair<pair<int,string>,string>> sort1;

        for(int i=0 ; i<n; i++){
            if(!isActive[i]) continue;
            if(busi.find(businessLine[i])==busi.end()) continue;
            if(code[i].empty()) continue;
            bool isCode = true;
            for(char c: code[i]){
                if(!(isalnum(c)|| c=='_')){
                    isCode = false;
                    break;
                }
            }
            if(!isCode) continue;
            int si = busi[businessLine[i]];
            sort1.push_back({{si,code[i]},code[i]});
        }
        sort(sort1.begin(),sort1.end());
        vector<string> s2;
        for(auto& i : sort1){
            s2.push_back(i.second);
        }
        return s2;
    }
};