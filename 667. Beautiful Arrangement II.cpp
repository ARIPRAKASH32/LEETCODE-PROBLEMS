class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> a(n);
        a[0] = 1;
        int i;
        int cnt = k;
        for(i = 1; i<=cnt; i++) {
            if (i%2==1) a[i] = a[i-1] + k;
            else a[i] = a[i-1] - k;
            k--;
        }
        for(i; i<n; i++) {
            a[i] = cnt + 2;
            cnt++;
        }
        return a;

    }
};
