class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1), mpp(n,1);

        for(int i = 0; i < n; i++) {
            mpp[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = 1 + dp[j];
                    mpp[i] = j;
                }
            }
        }

        int ans = -1, prev = -1;
        for(int i = 0; i < n; i++) {
            if(dp[i] > ans) {
                ans = dp[i];
                prev = i;
            }
        }

        vector<int> res;
        res.push_back(nums[prev]);
        while(mpp[prev] != prev) {
            prev = mpp[prev];
            res.push_back(nums[prev]);
        }
        return res;
    }
};