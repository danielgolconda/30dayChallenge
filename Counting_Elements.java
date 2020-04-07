class Solution {
    public int countElements(int[] arr) 
    {
     int n=arr.length,ans=0;
    TreeMap <Integer,Integer> t = new TreeMap <Integer,Integer>();
        for(int i=0;i<n;i++)
        {
            if(t.containsKey(arr[i]) == true)
            {
              //  System.out.println(2);
                Integer v = (Integer)t.get(arr[i]);
                t.put(arr[i],v+1);
            }
            else
            {
              //  System.out.println(1);
                t.put(arr[i],1);
            }
        }
        int k = t.size();
        int[] a = new int[k];
        int[] b = new int[k];
        int l = 0;
        for(Map.Entry<Integer,Integer> entry: t.entrySet())
        {
            a[l] = entry.getKey();
            b[l] = entry.getValue();
            l++;
        }
        for(int i=1;i<k;i++)
        {
            if(a[i] - a[i-1] == 1)
            {
                ans += b[i-1];
            }
         }
        return ans;
    }
    
}
