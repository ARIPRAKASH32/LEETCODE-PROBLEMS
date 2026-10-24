class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        while (a > 0 || b > 0) {
            int n = ans.size();
            if (n >= 2 && ans[n-1] == 'a' && ans[n-2] == 'a') {
                ans.push_back('b');
                b--;
            } 
            else if (n >= 2 && ans[n-1] == 'b' && ans[n-2] == 'b') {
                ans.push_back('a');
                a--;
            } 
            else if (a >= b && a > 0) {
                ans.push_back('a');
                a--;
            } 
            else {
                ans.push_back('b');
                b--;
            }
        }
        return ans;
    }
};
