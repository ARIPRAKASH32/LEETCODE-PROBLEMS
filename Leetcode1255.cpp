class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for(auto &c : letters){
            v1[c-'a']++;
        }
        int a =0;
        bt(words, score , v1 , v2 ,0 , 0, a);
        return a;
    }

    void bt(vector<string>&words , vector<int>&score , vector<int>count , vector<int>lettersCount , int pos , int temp , int &ans){
        for(int i = 0; i < 26; i++){
            if(lettersCount[i] > count[i]) return;
        }
        ans = max(ans, temp);
        for(int i = pos; i < words.size(); i++){
            for(auto& c : words[i]){
                lettersCount[c - 'a']++;
                temp+=score[c - 'a'];
            }
            bt(words, score, count, lettersCount, i + 1, temp, ans);
            for(auto& c : words[i]){
                lettersCount[c - 'a']--;
                temp-=score[c - 'a'];
            }
        }
    
    }
};