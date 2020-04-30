/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    // Similar to searching an element in the row and col sorted 2D array
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> p = binaryMatrix.dimensions();
        int n=p[0],m=p[1];
        int res = INT_MAX;
        int i=0,j=m-1;
        while(i >= 0 && j >= 0 && i < n && j < m)
        {
            int ele = binaryMatrix.get(i,j);
            if(ele == 1)
            {
                res = min(res,j);
                j--;
            }
            else
            {
                i++;
            }
        }
        if(res == INT_MAX)
        {
            return -1;
        }
        return res;
    }
};
