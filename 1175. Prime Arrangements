class Solution {
public:
    int power = 1000000007;

    bool isprime(int n){
        for(int i = 2; i*i<=n; i++)
        if(n%i == 0) return false;

        return true;
    }

    int fact(int n){
        long long int f = 1;
        for(int i = 1; i<=n; i++){
            f = (f * i) % power;
        }
        return f;
    }

    int numPrimeArrangements(int n) {
        int prime = 0;
        for(int i = 2; i<=n; i++){
            if(isprime(i)) prime++;
        }

        int total_prime = fact(prime), total_non_prime = fact(n - prime);
        int ans = (1LL * total_prime * total_non_prime) % power;
        return ans;
    }
};
