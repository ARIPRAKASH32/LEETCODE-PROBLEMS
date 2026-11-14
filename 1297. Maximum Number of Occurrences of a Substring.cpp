class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        unordered_map<string,int> mp;
        for(int k=minSize;k<=minSize;k++){
            unordered_map<char,int> track;
            int count = 0;
            int i=0,j=0;

            while(j<s.length()){
                track[s[j]]++;
                if(track[s[j]] == 1){
                    count++;
                }
                

                if((j-i+1)<k){
                    j++;
                }else{
                    if(count <= maxLetters){
                        mp[s.substr(i,(j-i+1))]++;
                    }
                    track[s[i]]--;
                    if(track[s[i]] == 0)
                        count--;
                    i++;j++;
                }
            }
        }
        int mx = 0;
        for(auto i:mp){
            mx = max(mx,i.second);
        }
        return mx;
    }
};
