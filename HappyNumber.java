class Solution {
    // Creating an Empty TreeSet to keep track of distinct objects because 
    // in the question it is said that there is a possibility of forming a loop
    TreeSet <Integer> t = new TreeSet<Integer>();
    public boolean isHappy(int n) {
      // Base Condition in the Recursive approach
        if(n == 1)
        {
            return true;
        }
        else
        {
        // If there exists a loop we can simply return false as it is not an Happy Number
            if(t.contains(n) == true)
            {
                return false;
            }
            else
            {
            // We add the number into the TreeSet as to keep track of it
                t.add(n);
                
                // Perform the squaring of individual digits as said in the question
                int h = 0;
                while(n > 0)
                {
                    int r=(n%10);
                    h+=(r*r);
                    n = (n/10);
                }
                // Recur for the new number that is formed
                return isHappy(h);
            }
        }
        
    }
}
