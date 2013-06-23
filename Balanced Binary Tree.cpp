/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isBalanced(TreeNode* root, int& depth)
    {
        if (root == nullptr)
        {
            depth = 0;
            return true;
        }
        
        int left_depth = 0;
        if (!isBalanced(root->left, left_depth))
        {
            return false;
        }
        
        int right_depth = 0;
        if (!isBalanced(root->right, right_depth))
        {
            return false;
        }
        
        depth = max(left_depth, right_depth) + 1;
        return (left_depth == right_depth || left_depth == right_depth + 1 || left_depth + 1 == right_depth);
    }
    
    bool isBalanced(TreeNode* root)
    {
        int depth = 0;
        return isBalanced(root, depth);
    }
};
