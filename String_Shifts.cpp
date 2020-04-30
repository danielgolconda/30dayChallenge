class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) 
    {
     string res="";
        int n=shift.size();
        // 0 for left shit and 1 for right shift 
        int ls = 0,rs = 0;
    for(int i=0;i<n;i++)
    {
        if(shift[i][0] == 0)
        {
            ls+=shift[i][1];
        }
        else
        {
            rs+=shift[i][1];
        }
    }
        cout<<ls<<" "<<rs<<endl;
       if(ls > rs)
       {
           ls-=rs;
           deque <char> dq;
           deque <char> :: iterator it;
           for(int i=0;i<s.size();i++)
           {
               dq.push_back(s[i]);
           }
           while(ls--)
           {
               char f = dq.front();
               dq.pop_front();
               dq.push_back(f);
           }
           for(it = dq.begin();it!=dq.end();it++)
           {
               res+=(*it);
           }
           return res;
       }
        else if(ls < rs)
        {
             rs-=ls;
            deque <char> dq;
           deque <char> :: iterator it;
            for(int i=0;i<s.size();i++)
           {
               dq.push_back(s[i]);
           }
            while(rs--)
            {
                char b=dq.back();
                dq.pop_back();
                dq.push_front(b);
            }
             for(it = dq.begin();it!=dq.end();it++)
           {
               res+=(*it);
           }
           return res;
        }
        else
        {
            return s;
        }
       
    }
};
