class Solution {
public:
    int msb(int x)
    {
        int p = 0;
        while(x)
        {
            p++;
            x = (x>>1);
        }
        return p-1;
    }
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        while(m && n)
        {
            int lb1 = msb(m);
            int lb2 = msb(n);
            if(lb1 != lb2)
            {
                return res;
            }
            m = (m - (1<<lb1));
            n = (n - (1<<lb2));
            res+=(1<<lb1);
        }
        return res;
    }
};
