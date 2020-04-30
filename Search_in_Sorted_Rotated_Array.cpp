class Solution {
public:
    int  findMinIndex(vector<int>& a,int n,int target)
    {
        if(a[0] < a[n-1])
        {
            return 0;
        }
        int start = 0,end = n-1;
        while(start <= end)
        {
            int mid = start + ((end-start)/2);
            if(a[mid] > a[mid+1])
            {
                return mid+1;
            }
            if(a[mid] < a[mid-1])
            {
                return mid;
            }
            if(a[start] < a[mid])
            {
                start = mid+1;
            }
            if(a[mid] < a[end])
            {
                end = mid-1;
            }
        }
        return -1;
    }
    int binary_s(vector<int>& a,int start,int end,int target)
    {
        while(start <= end)
        {
            int mid = start+((end-start)/2);
            if(a[mid] == target)
            {
                return mid;
            }
            else if(target < a[mid])
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // Step - 1 : First find the index of the minimum element,
        // Divide the array into two equal halves
        // Binary Search for the element in both the halves
        
        int n = nums.size();
        if(n == 0)
        {
            return -1;
        }
        if(n == 1)
        {
            if(nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        int minIndex =  findMinIndex(nums,n,target);
        int ls = binary_s(nums,0,minIndex-1,target);
        int rs = binary_s(nums,minIndex,n-1,target);
        
        return max(ls,rs);
        
    }
};
