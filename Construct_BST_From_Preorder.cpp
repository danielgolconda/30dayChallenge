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
    TreeNode* construct(TreeNode* root,int k)
    {
        if(root == NULL)
        {
            root = new TreeNode(k);
            return root;
        }
        if(root->val < k)
        {
            root->right = construct(root->right,k);
        }
        else
        {
            root->left = construct(root->left,k);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<n;i++)
        {
            root = construct(root,preorder[i]);
        }
        return root;
    }
};
