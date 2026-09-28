class Solution {

private:
    // Helper for KMP: Generic Pattern Matching
    bool kmpSearch(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        if (m == 0)
            return true;

        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m;) {
            if (pattern[i] == pattern[len])
                lps[i++] = ++len;
            else if (len)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }

        for (int i = 0, j = 0; i < n;) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == m)
                    return true;
            } else  {
                if (j)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }

    // Helper for Z-Algo: Generic Prefix Matching
    bool zSearch(string S) {
        int n = S.size();
        // Here we need to find b's length. Let's assume pattern length is m
        // Finding '#' position to identify pattern length
        int m = S.find('#');
        vector<int> Z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r)
                Z[i] = min(r - i + 1, Z[i - l]);
            while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]])
                Z[i]++;
            if (Z[i] > 0 && i + Z[i] - 1 > r) {
                l = i;
                r = i + Z[i] - 1;
            }
            if (Z[i] == m)
                return true;
        }
        return false;
    }

public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();
        string temp = "";
        int count = 0;

        // 1. Keep repeating 'a' until its length is at least 'm'
        while (temp.size() < m) {
            temp += a;
            count++;
        }

        // --- CHOICE 1: Built-in find() ---
        // if (temp.find(b) != string::npos) return count;
        // if ((temp + a).find(b) != string::npos) return count + 1;
        // return -1;

        // --- CHOICE 2: KMP O(N + M) ---
        // Replace Choice 1 with this logic
        // if (kmpSearch(temp, b))
        //     return count;
        // if (kmpSearch(temp + a, b))
        //     return count + 1;
        // return -1;

         // --- CHOICE 3: Z-Algorithm O(N + M) ---
        // Replace Choice 1 with this logic
        //if (zSearch(b + "#" + temp)) return count;
        //if (zSearch(b + "#" + temp + a)) return count + 1;
        //return -1;

        // --- CHOICE 4: Rolling Hash O(N + M) ---
        temp+=a;
        int nn=temp.size();
        typedef long long ll;
        ll h=1,base=31,MOD = 1e9 +7;
        ll patHash = 0,textHash = 0;

        for(int i=0;i<m;i++){
            if(i>0) h=(h*base)%MOD;
            patHash=(patHash*base + b[i])%MOD;
            textHash=(textHash*base + temp[i])%MOD;
        }
        int i=0;bool match =false;
        for(;i<=nn-m;i++){
            if(patHash == textHash){
                if(temp.substr(i,m) == b) { match =true; break;}
            }
            if(i<nn-m){
                textHash = (base*(textHash- h*temp[i]) + temp[i+m])%MOD;
                if(textHash<0)textHash+=MOD;
            }
        }
        if(match){
            if(i+m>nn-n){
                return count +1;
            }else{
                return count;
            }
        }
        return -1;


        // Choice_5 ---2 pointer---

        // Try every index of string 'a' as a potential starting point
        for (int i = 0; i < n; i++) {
            int j = 0;
            // While characters match and we haven't reached the end of 'b'
            while (j < m && a[(i + j) % n] == b[j]) {
                j++;
            }

            // If j reached m, it means we found a complete match!
            if (j == m) {
                // Calculation: i is the starting offset, m is the pattern length.
                // This formula calculates the number of 'a' blocks involved.
                return (i + m + n - 1) / n;
            }
        }

        return -1;
    
    }
};
