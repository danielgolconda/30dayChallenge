class Solution {
public:
    int dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& vis,int n,int m)
    {
        if(x >= n || x<0 || y >= m || y < 0)
        {
            return 0;
        }
        if(grid[x][y] == '0')
        {
            return 0;
        }
        if(vis[x][y] == 1)
        {
            return 0;
        }
        else
        {
            vis[x][y] = 1;
            dfs(x+1,y,grid,vis,n,m);
            dfs(x,y+1,grid,vis,n,m);
            dfs(x-1,y,grid,vis,n,m);
            dfs(x,y-1,grid,vis,n,m);
            return 1;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0,n=grid.size();
        vector<vector<int>> vis(1111,vector<int>(1111,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    ans += dfs(i,j,grid,vis,n,grid[i].size());
                }
            }
        }
        return ans;
        
    }
};
