class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int n,int m,int x,int y)
    {
        if(x < 0 || y < 0 || x > n-1 || y > m-1)
        {
            return INT_MAX;
        }
        if(x == 0 && y == 0)
        {
            return grid[x][y];
        }
        if(dp[x][y] != -1)
        {
            return dp[x][y];
        }
        return dp[x][y] = grid[x][y] + min(solve(grid,dp,n,m,x-1,y),solve(grid,dp,n,m,x,y-1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,dp,n,m,n-1,m-1);
    }
};
