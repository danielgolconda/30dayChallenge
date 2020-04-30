class Solution {
public:
    int dp[55555];
    int solve(vector<int>& nums,int idx,int n)
    {
        if(idx == n-1)
        {
            return 1;
        }
        if(idx > n-1)
        {
            return 0;
        }
        if(dp[idx] != -1)
        {
            return dp[idx];
        }
        int ans = 0;
        int k =nums[idx];
        int i=idx;
        for(int i=idx+1;i<=idx+nums[idx] && i < n;i++)
        {
            ans|=solve(nums,i,n);
        }
        return dp[idx] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        if(solve(nums,0,n) == 1)
        {
            return true;
        }
        else
        {
            return false;    
        }
    }
};
