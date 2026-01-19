class Solution {
public:
    long long minMoves(vector<int>& a) {
        long long s = accumulate(a.begin() , a.end(),0LL);
        if(s < 0){
            return -1;
        }
        int in = -1;
        int n = a.size();
        for(int i=0 ; i<n ; i++){
            if(a[i]<0){
                in = i;
                break;
            }
        }
        if(in == -1){
            return 0;
            
        }
        int l = (in+n-1)%n;
        int r = (in+1)%n;
        long long d = 1;
        long long cur =-1LL * a[in];
        long long m =0;

        while(cur >0){
            long long v =(long long)a[l]+(long long)a[r];
            long long temp = min(cur , v);
            m += temp *d;
            cur -= temp;
            d+=1;
            l = (l+n-1)%n;
            r = (r+1)%n;        
        }
        return m;
    }
};