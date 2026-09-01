// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    long long cache = 0;
    long long upper = 1;
    
public:
    int rand10() {
        while (true) {
            while (upper < 10) {
                cache = cache * 7 + (rand7() - 1);
                upper *= 7;
            }
            
            long long maxUsable = (upper / 10) * 10;
            
            if (cache < maxUsable) {
                int result = cache % 10 + 1;
                cache /= 10;
                upper /= 10;
                return result;
            }
            
            cache -= maxUsable;
            upper -= maxUsable;
        }
    }
};
