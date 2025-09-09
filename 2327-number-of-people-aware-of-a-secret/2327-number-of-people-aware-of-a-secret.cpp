class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0); // dp[i] = new people who learn on day i
        dp[1] = 1;
        
        long long share = 0; // running total of people who can share
        for (int day = 2; day <= n; day++) {
            // people start sharing after "delay"
            if (day - delay >= 1) {
                share = (share + dp[day - delay]) % MOD;
            }
            // people forget after "forget"
            if (day - forget >= 1) {
                share = (share - dp[day - forget] + MOD) % MOD;
            }
            dp[day] = share; // new learners today
        }
        
        // answer = people who haven't forgotten by day n
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
