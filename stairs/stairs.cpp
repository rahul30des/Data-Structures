public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climbStairsUtil(n, dp);
    }
    // Time Complexity O(2^n) - exponential
    // Space Complexity O(n)
    int climbStairsUtil(int n, vector<int>& dp) {
        if(dp[n] == -1) {
            if(n == 0) {
                dp[n] = 0;
            } else if (n == 1) {
                dp[1] = 1;    
            } else if (n == 2) {
                dp[2] = 2;
            } else {
                dp[n] = climbStairsUtil(n-2, dp) + climbStairsUtil(n-1, dp);
            }
        }
        return dp[n];
    }
};
