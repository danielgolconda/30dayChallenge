class Solution {
public:
    // Helper Function to compute the Sum of subarrays recursively
    int maxSum(vector<int>& nums,int low,int high)
    {
        // incorrect condition 
        if(low > high)
        {
            // we return minimum value because it is an maximisation function.
            return INT_MIN;
        }
        // Only one element is considered 
        if(low == high)
        {
            // If only one element is present in the array the maximum sum = element itself.
            return nums[low];
        }
        // Dividing the functioning into two equal halves.
        int mid=((low+high)/2);
        
        // Calling the left half it is a similar call to that one we do  in binary search.
        int lans = maxSum(nums,low,mid);
        
        // Calling the right half
        int rans = maxSum(nums,mid+1,high);
        
        // Now that we have called for both the halves the answer may also lie in the segment
        // that may belong partially to the first half and partially to the second half
        
        // We do initialize leftMax and rightMax to 0 because the maximum sum can be negative as well.
        int leftMax = nums[mid];
        int rightMax = nums[mid+1];
        
        int sum = 0;
        // Calculating the maxiumum sum for the left half
        for(int i = mid;i>=low;i--)
        {
            sum += nums[i];
            leftMax = max(leftMax,sum);
        }
        sum = 0;
        // Calculating the maxiumum sum for the right half
        for(int i = mid+1;i<=high;i++)
        {
            sum += nums[i];
            rightMax = max(rightMax,sum);
        }
        
        // We now return the maximum of lefthalf,righthalf,and the 
        // maximum sum of the common segment connecting both the halves
        return max(lans,max(rans,leftMax+rightMax));
    }
    
    int maxSubArray(vector<int>& nums) 
    {
     int n=nums.size();
        // Calling the helper function 
        return maxSum(nums,0,n-1);
    }
};
