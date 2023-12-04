#include<iostream>
#include<vector>

using namespace std;

// Time Complexity O(n) - linear
// Space Complexity O(n) - linear
int minStairs(int n) {
   vector<int> dp(n+1, 2); 
   dp[0] = 0;
   dp[1] = 1;
   for(unsigned int i = 3; i <= n; i++) {
       dp[i] = dp[i - 1] + dp[i - 2];
   }
   return dp[n];
}

int main() {
    int n = 5;
    cout<<minStairs(n);
    return 0;
}
