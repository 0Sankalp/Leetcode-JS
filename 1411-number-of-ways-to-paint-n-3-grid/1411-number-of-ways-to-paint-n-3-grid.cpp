class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
        long a = 6; // ABA patterns
        long b = 6; // ABC patterns
        
        for (int i = 2; i <= n; i++) {
            long newA = (3 * a + 2 * b) % MOD;
            long newB = (2 * a + 2 * b) % MOD;
            a = newA;
            b = newB;
        }
        
        return (a + b) % MOD;
    }
};
