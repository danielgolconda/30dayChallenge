class Solution {
public:
    // Initialise empty set to keep track of the digits because
    // in the question it is said that there is a possibility of forming a loop
    set <int> st;
    bool isHappy(int n) 
    {
        // Base Condition
        if(n == 1)
        {
            return true;
        }
        // Searching if element is already present in the set, if it is present then we can say that it will form a loop and return false
        
        // we can also use find() method
        if(binary_search(st.begin(),st.end(),n))
        {
            return false;
        }
        else
        {
            // We add the number into the Unordered_Set as to keep track of it
                st.insert(n);
                
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
};
