class Solution {
    public boolean backspaceCompare(String s, String t) 
    {
        int n=s.length(),m=t.length();
        Stack<String> a = new Stack<String>();
        Stack <String> b = new Stack <String>();
        for(int i=0;i<n;i++)
        {
            if(a.isEmpty() == true)
            {
                if(s.charAt(i) != '#')
                {
                    a.push(Character.toString(s.charAt(i)));
                }
            }
            else
            {
                if(s.charAt(i) == '#')
                {
                    a.pop();
                }
                else
                {
                  a.push(Character.toString(s.charAt(i)));
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(b.isEmpty() == true)
            {
                if(t.charAt(i) != '#')
                {
                    b.push(Character.toString(t.charAt(i)));
                }
            }
            else
            {
                if(t.charAt(i) == '#')
                {
                    b.pop();
                }
                else
                {
                        b.push(Character.toString(t.charAt(i)));
                }
            }
        }
        System.out.println(a);
        System.out.println(b);
        if(a.equals(b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
