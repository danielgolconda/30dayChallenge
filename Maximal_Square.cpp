class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n == 0)
        {
            return 0;
        }
        int m=mat[0].size(),flag = 0;
        vector<vector<int>> dup(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dup[i][j] = 0;       
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == 0 || j == 0)
                {
                    if(mat[i][j] == '1')
                    {
                        dup[i][j] = 1;
                    }
                    else
                    {
                        dup[i][j] = 0;
                    }
                }
            }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j] != '0')
                {
                    dup[i][j] = 1+min(dup[i][j-1],min(dup[i-1][j],dup[i-1][j-1]));
                }
            }
        }
        int res = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res = max(res,dup[i][j]);       
            }
        }
        
        
        return res*res;
  }
};
