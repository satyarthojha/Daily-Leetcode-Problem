//
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 1;
        vector<vector<int>>dp(n,vector<int>(k+1,1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int parity = (nums[i] + nums[j]) % k;
                dp[i][parity] = max(dp[i][parity],dp[j][parity] + 1);
                maxLen = max(maxLen,dp[i][parity]);
            }
        }
        return maxLen;
    }
};