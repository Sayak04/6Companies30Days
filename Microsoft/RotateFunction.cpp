class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            ans += i * nums[i];
            sum += nums[i];
        }
        int temp = ans;
        // F(1) = F(0) + Sum_Total - n*nums[n-1]
        // F(2) = F(1) + Sum_Total - n*nums[n-2]
        // ..
        for(int i = 1; i < n; i++) {
            temp += sum - (n * nums[n - i]);
            ans = max(ans, temp);
        }
        return ans;
    }
};