class Solution {
public:
     bool solve(string &s,int i,vector<int>&v){
        if(i==s.length()&&v.size()>=3){
            return true;
        }
        for(int j=i;j<s.length();j++){
            string t=s.substr(i,j-i+1);
            //to deal with leading zeroes
            if(s[i]=='0' && j>i){
                return false;
            }
            //to prevent overflow
            if(stoll(t)>=INT_MAX)return false;
            long long temp=stoll(t);
            //backtracking
            if(v.size()<=1 || temp==v[v.size()-2]*1LL+v[v.size()-1]*1LL){
                v.push_back(temp);
                if(solve(s,j+1,v)) return true;
                v.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int>ans;
        solve(num,0,ans);
        return ans;
    }
};
