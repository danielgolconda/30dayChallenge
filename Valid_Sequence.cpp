/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,string curr,string res)
    {
        if(root == NULL)
        {
            return false;
        }
        if(root->left == NULL && root->right == NULL)
        {
            curr+=to_string(root->val);
            if(curr == res)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return solve(root->left,curr+to_string(root->val),res)||solve(root->right,curr+to_string(root->val),res);
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int n=arr.size();
        string res="";
        for(int i=0;i<n;i++)
        {
            res+=to_string(arr[i]);
        }
        string curr="";
       return solve(root,curr,res);
    }
};
