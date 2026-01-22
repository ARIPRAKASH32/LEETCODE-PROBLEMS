class Solution {
    public long sumOfLargestPrimes(String s) {
        Set<Long> pri = new HashSet<>();
        int n = s.length();
        for(int i=0 ; i<n ; i++){
            long t = 0;
            for(int j=i;j<n ; ++j){
                t = t*10+(s.charAt(j)-'0');
                if(ispri(t)){
                    pri.add(t);
                }
            }
        }
        List<Long> primes = new ArrayList<>(pri);
        Collections.sort(primes);
        int m = primes.size();
        if(m<3){
            long sum = 0;
            for(long p:primes) sum+=p;
            return sum;
        
            
        }
        return primes.get(m-1)+ primes.get(m-2)+primes.get(m-3);
    }
    private boolean ispri(long n){
            if(n<2) return false;
            for(long i=2 ; i*i<=n ; ++i) 
                if(n%i==0) return false;
            return true;
        }
}