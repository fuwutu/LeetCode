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
    int maxSidePathSum(TreeNode *root, int& max_path_sum)
    {
        int max_root_sum = root->val;
        
        int left_sum = 0;
        if (root->left != NULL)
        {
            left_sum = maxSidePathSum(root->left, max_path_sum);
            if (left_sum > 0)
            {
                max_root_sum += left_sum;
            }
        }
        
        int right_sum = 0;
        if (root->right != NULL)
        {
            right_sum = maxSidePathSum(root->right, max_path_sum);
            if (right_sum > 0)
            {
                max_root_sum += right_sum;
            }
        }
        
        max_path_sum = max(max_path_sum, max_root_sum);
        
        return root->val + max(max(left_sum, right_sum), 0);
    }
    
    int maxPathSum(TreeNode *root)
    {
        int max_path_sum = root->val;
        maxSidePathSum(root, max_path_sum);
        return max_path_sum;
    }
};
