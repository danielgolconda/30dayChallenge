class Solution {
    // Time Complexity : Linear 
    // Dynamic Programming solution using inclusion-exclusion principle
    public int maxSubArray(int[] nums) 
    {
        // Base Conditions
        // If no elements are present in the array then the maxSum is 0
        if(nums.length == 0)
        {
            return 0;
        }
        // If a single element is present in the array then the maxSum ==element itself
       if(nums.length == 1)
       {
           return nums[0];
       }
        int n=nums.length;
        // Here s = local_maximum and b = the globalmaxima or the solution
        int s = 0,b = Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            // Here first we check the maximum(exclude_element,include_element)
            // s+nums[i]  = add element to the sum
            // nums[i] = leave the subarray and form the subarray from this point.
            s = Math.max(nums[i],s+nums[i]);
            
            // maximum(local_maxima) = global_maxima/ answer
            b = Math.max(s,b);
        }
        // returning answer
        return b;
    }
}
