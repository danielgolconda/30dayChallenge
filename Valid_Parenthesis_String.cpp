class Solution {
public:
    bool checkValidString(string s) {
          int n=s.size();
    stack <int> open,ast;
    for(int i=0;i<n;i++)
    {
      if(s[i] == '(')
        {
          open.push(i);
        }
        else if(s[i] == '*')
        {
          ast.push(i);
        }
        else
        {
          if(!open.empty())
          {
            open.pop();
          }
          else if(!ast.empty())
          {
            ast.pop();
          }
          else
          {
            return false;
          }
        }
      }
    while(open.empty() == false && ast.empty() == false)
    {
      if(open.top() > ast.top())
      {
        return false;
      }
      else
      {
        open.pop();
        ast.pop();
      }
    }
    if(open.empty())
    {
      return true;
    }
    else
    {
        return false;
    }
    }
};
