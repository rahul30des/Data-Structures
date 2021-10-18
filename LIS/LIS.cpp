class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        unsigned int arr_size = arr.size();
        int max_so_far = INT_MIN;
        vector<int> dp(arr_size, 1);
        
        for(unsigned int i = 0; i < arr.size(); i++) {
            for(unsigned int j = 0; j < i; j++) {
                if(arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] +1);
                    max_so_far = max(max_so_far, dp[i]);
                }   
            }
        }
        return max_so_far;
    }
};
