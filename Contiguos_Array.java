class Solution {
    public int findMaxLength(int[] nums) {
        int n=nums.length;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = -1;
            }
        }
        HashMap <Integer,Integer> mp = new HashMap<>();
        int sum = 0;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum == 0)
            {
                ans = i+1;
            }
            if(mp.containsKey(sum) == false)
            {
                mp.put(sum,i);
            }
            else
            {
             int k = mp.get(sum);
            ans = Math.max(ans,i-k);
            }
        }
        return ans;
    }
}
